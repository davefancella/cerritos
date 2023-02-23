#!/bin/bash

# Usage: linux_to_windows.sh <arguments to CMake>
# call from your build directory. So, for example, you would do starting from the main source:
# > mkdir build_win64
# > cd build_win64
# > ../crosscompile/linux_to_windows.sh

# Prerequisites (aside from conan and cmake):
# Install mingw-w64
#   Ubunutu: sudo apt-get install g++-mingw-w64 gcc-mingw-w64
#   Arch: sudo pacman -S mingw-w64-crt

# Documentation this is based on:
# https://docs.conan.io/1/systems_cross_building/cross_building.html#cross-building-examples-profiles
# https://docs.conan.io/2.0/tutorial/consuming_packages/cross_building_with_conan.html
# https://www.aroeira.io/post/cross-compile/

set -x 

SOURCE_PATH=$(dirname $(dirname $0))
shift

# see if we need to update the conan configuration
if test "${SOURCE_PATH}"/conanfile.txt -nt conan_paths.cmake || test "$0" -nt conan_paths.cmake; then
    rm -f CMakeCache.txt conan.lock conan_paths.cmake

    # determine mingw version

    # generate profile data
    toolchain=/usr/x86_64-w64-mingw32 # Maybe adjust this path
    target_host=x86_64-w64-mingw32
    cc_compiler=gcc
    cxx_compiler=g++

    # somehow, one has to set this manually to a cross compiler, or some conan builds fail
    export CC=$target_host-$cc_compiler
    export CXX=$target_host-$cxx_compiler

    # horrible way to fetch conan compliant version from mingw.
    # conan expects at most two versions segments, no trailing zero. So 1, 1.1, 2, 2.1, 2.2
    #                                                                  # to here: line with version at the end
    #                                                                                      # to here: just the version, bits before cut off
    #                                                                                                                                 # to here: cut off any more than two version segments
    #                                                                                                                                                      # cut off trailing 0
    compiler_version=$($target_host-$cc_compiler --version | head -n 1 | sed -e 's/.* //g' | sed -E 's/([^\.]*)\.([^\.]*)\..*/\1.\2/' | sed -e 's/^{0}/\0/')

    # compose profle
    cat > win64.profile << EOF
        toolchain=$toolchain
        target_host=$target_host
        cc_compiler=$cc_compiler
        cxx_compiler=$cxx_compiler

        [buildenv]
        CONAN_CMAKE_FIND_ROOT_PATH=\$toolchain  # Optional, for CMake to find things in that folder
        CONAN_CMAKE_SYSROOT=\$toolchain  # Optional, if we want to define sysroot
        CHOST=\$target_host
        AR=\$target_host-ar
        AS=\$target_host-as
        RANLIB=\$target_host-ranlib
        CC=\$target_host-\$cc_compiler
        CXX=\$target_host-\$cxx_compiler
        STRIP=\$target_host-strip
        RC=\$target_host-windres

        [settings]
        # We are cross-building to Windows
        os=Windows
        arch=x86_64
        compiler=gcc

        compiler.version=$compiler_version
        #compiler.version=12
        compiler.libcxx=libstdc++11
        build_type=Release
EOF

    #conan install "${SOURCE_PATH}" -pr:b=default -pr:h=win64.profile --no-imports || exit $?

    # use the generated profile to make conan install the correct cross compilation libraries
    #conan install "${SOURCE_PATH}" --build=missing -s:b os_build=Linux -pr=win64.profile || exit $?
    conan install "${SOURCE_PATH}" --build=missing -pr:b=default -pr:h=win64.profile || exit $?
fi

# use the conan provided build environment from here on
source ./conanbuild.sh || exit $?

# build configuration with CMAKE. All further arguments are passed to it
# USE_OPENAL=OFF is required because we can't install OpenAL over conan and
# cmake would pick up a native version, if available
cmake -DUSE_OPENAL=OFF "${SOURCE_PATH}" "$@" || exit $?

# build with maximum paralellism
cmake --build . -j $(( `nproc` + 1 )) || exit $?

