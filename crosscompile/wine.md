# How to compile for Windows under Wine

Note: This is work in progress and does not yet work to the end. It maybe never will.

## Setup

Basically, follow the instructions for native Windows builds. 
However, winget does not work in wine, so you have to install everything by hand or with winetricks.
* Git: Not required, just use git and your favorite shell from the Linux side
* VS Code: Not required

* CMake:
    * Comfortable:
        > winetricks cmake
    * Manual:
        https://cmake.org/download/

        Pick the .msi installer


    Choose 'Add CMake to system PATH' (current user or all users should not matter)

* Python: https://www.python.org/downloads/windows/

    Pick the 64 bit zip (embeddable) archive

    Unzip to your Windows C drive (~/.wine/drive_c), directory Python

    Unzip the contained python*.zip directly there, too

    Add that folder to the Windows search path: execute
    > wine regedit

    navigate to HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment,
     edit the value PATH; append ';C:\Python;C:\Python\Scripts;C:\Program Files\CodeBlocks\MinGW\bin'.
     (the MinGW bit is for code::blocks later)

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

And then you are stuck.

## The following steps were tried, too

* Visual Studio Build Tools:
    > winetricks vstools2019 -q

    Result: Could not install.

* Instead of the big Visual Studio, you can try Code::Blocks with mingw. Download from https://www.codeblocks.org/downloads/binaries/#imagesoswindows48pnglogo-microsoft-windows
    Pick the *mingw-setup.exe variant
    > wine ./codeblocks-20.03mingw-setup.exe

    Result: Installs fine, runs fine, autodetected by conan. However, 'conan install' then fails to build everything.
