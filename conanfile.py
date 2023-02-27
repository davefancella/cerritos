# standard conan instructions:
# make a new build directory, change into it
# install dependencies with
# conan install <path to source> --build=missing

from conans import ConanFile, CMake

class CerritosConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"

    generators = \
        "cmake_find_package", \
        "cmake_paths", \
        "CMakeDeps", \
        "VirtualBuildEnv"

    requires = \
        "sdl/[^2.0 >=2.26.1]", \
        "sdl_ttf/[^2.0 >=2.0.15]", \
        "sdl_image/[^2.0 >=2.0.5]", \
        "libpng/[^1]", \
        "xz_utils/[^5]"

    # libpng and xy_utils are for conflict resolution; apparently it is enough to just state the conflicting transitive
    # dependencies with a broad version specification.


    # graphviz is not in Conan. Figures, it is a perl program.
    # Hope it is optional or can be manually installed if needed.

    def configure(self):
        if self.settings.os != "Macos" and self.settings.compiler != "Visual Studio":
            self.options["sdl"].iconv = False

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib", dst="bin", src="lib")
