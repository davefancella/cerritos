# How to compile for Windows under Wine

## Why? I mean, why? Why not just use cross compilation?

You want the deployed build to be as similar as possible to a build you can actually debug. So,
ideally, you would want to deploy builds done on a Windows machine with Windows development tools,
because that is where your hordes of Windows developers would be working.
But you may not have one readily available, so the next best thing is to use Windows build tools
on Wine.

Also, using this way, all the build tools know they are compiling on Windows for Windows and will
name their output files accordingly.

## Problem

Conan can in principle build all our dependencies. On Wine, however, that fails, because Conan wants
to use msys2 to be able to use Unix-like build methods, and that does not work in Wine. There are no
usable prebuilt packages available.

## Workaround

Conan can use packages prebuilt with the cross compiler, provided the used compilers are similar enough.
A suitable environment with all the right tools on the Windows side is [w64devkit](https://github.com/skeeto/w64devkit).
It uses the same MinGW base as the cross compiler recommended in linux_to_windows.sh.

## Setup

Basically, follow the instructions for native Windows builds. 
However, winget does not work in wine, so you have to install everything by hand or with winetricks.
* Git: Not required, just use git and your favorite shell from the Linux side
* VS Code: Not required

* CMake:
    * Comfortable:
        > winetricks cmake
    * Manual:
        [Download](https://cmake.org/download/), pick the .msi installer


    Choose 'Add CMake to system PATH' (current user or all users should not matter)

* w64devkit:
    [Download](https://github.com/skeeto/w64devkit/releases), Pick the most basic w64devkit-*.zip

    Unzip to your Windows C drive (~/.wine/drive_c) directly, it will go to the folder
    w64devkit. Nothing more is required.

* Python:

    [Download](https://www.python.org/downloads/windows/), pick the 64 bit zip (embeddable) archive

    Unzip to your Windows C drive (~/.wine/drive_c), directory Python

    Unzip the contained python*.zip directly there, too

    Add that folder to the Windows search path: execute
    > wine regedit

    navigate to HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment,
     edit the value PATH; append ';C:\Python;C:\Python\Scripts;C:\w64devkit\bin'.
     (the w64devkit bit also makes w64devkit your default dev environment)

* Pip: Via the get-pip.py method: https://pip.pypa.io/en/stable/installation/#get-pip-py
    > wget https://bootstrap.pypa.io/get-pip.py
    > wine python get-pip.py

    This installs the pip module in C:\Python\Lib\site-packages... where it is not found.
    Setting the PTHONPATH by any means to include it did not work for me (advice welcome),
    so I ended up just doing in ~/.wine/drive_c/Python:
    > ln -s Lib/site-packages/* .

* Conan: easy peasy if everything above went right:
    > wine pip install 'conan<2.0'

    Followed by another
    > ln -s Lib/site-packages/* .

    in ~/.wine/drive_c/Python.

## Now comes the magic bit

In Linux, at least once, do a cross compilation build with linux_to_windows.sh. It does not 
have to be a complete build, getting the Conan-managed dependencies compiled is enough.
These dependencies are residing in ~/.conan/data. Important: Make sure that the cross compilation
MinGW you installed is compatible with the MinGW version of w64devkit. If the cross compilation
one has the same or a lower major version, that usually is good enough.

The commands for that are, from the cerritos main directory:
> mkdir build_cross

> cd build_cross

> ../crosscompile/linux_to_windows.sh --cmake-should-fail

Keep the directory around for now, we will need it.

Then, also at least once, can be from the same directory, try to install
the dependencies via Conan. This will fail:

> cd ..

> mkdir build_win64

> cd build_win64

> wine conan install ..

But now you have Conan set up in your wine environment. It expects its dependencies
in C:\Users\\your unix username\\.conan\\data. So, you simply link that directory
and the one from the cross compilation together:

> rm -rf ~/.wine/drive_c/users/your unix username/.conan/data

> ln -sf ~/.conan/data ~/.wine/drive_c/users/your unix username/.conan/

That is not quite enough, though; Conan only uses compiled packages of the
correct configuration. We have to convince it that the cross compilation
configuration is identical to the Wine configuration. Conan uses profile files
for that. The one for cross compilation is still in `../build_cross/win64.profile`.
The one for the Wine compilation is in 
`~/.wine/drive_c/users/your unix username/.conan/profiles/default`. Open them both,
copy the values in the [settings] section from win64.profile to default.
The relevant ones would be os, arch, compiler, compiler.version, compiler.libcxx and 
build_type.

Here is also your chance to check whether the MinGW versions were compatible. In default,
Conan has detected the version of the one installed in Wine. So if you are making that
bigger in the major version, expect failures.

Then it is time for another go. This time, Conan should find and accept the precompiled
libraries.

> wine conan install ..

CMake needs a special parameter to create usable makefiles:
> wine cmake .. -G "MinGW Makefiles"

> wine cmake --build .
