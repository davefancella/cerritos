@page pathhandling How Cerritos Handles Paths

# Path Handling

Cerritos has a Path class that exists as a singleton for translating from
code to locations on disk.  The primary way to access this class is to
use the _PATH macro, which translates to Path::get() and returns the Path
object.  Typically, you would use _PATH.getFilepath(directory, filename) to
give you an absolute path on disk to the filename.

Here's what these things mean.

## Asset directory

Every game will ship with a bunch of data files that we call, in general,
assets.  Assets include everything from simple images, fonts, sprites, sound
effects, music, maps, etc.  Anything that's not code is called an "asset".
In some cases, even some embedded scripting can be considered an asset as
well.

For each platform, this asset directory is in a different place, and can
even be in a different place on different platforms.  For example, it's become
common in Linux distributions to use a "/usr/games" directory to put game
executables, and then "/usr/share/games" to put game assets.  Meanwhile,
in Windows, the classic location for everything was "c://Program Files", and
that has changed over the years depending on which version of Windows you
use.  

Additionally, you'll need your game to find its assets when run from a build
directory, and possibly when run from a single directory, regardless of platform,
because you decided to offer a binary .zip distribution.

Obviously, there's no One Way to find files, right?

That's what the Path object is for.

The standard way Cerritos expects to find it's files is in a specific directory
tree.  Each type of directory basically boils down to one of several options:

- Binary executable location
- Additional DLL location
- Assets
- Configuration


If you need more than that, well, the Path object is quite configurable.

## Asset Locations

All assets are assumed to be in a location in your source tree named assets
that is found one level up from your build directory.  When you write your
installer, or you use a package manager, you'll need to put them in a place
amongst all the system files on your target platform.  Cerritos makes no
assumptions, but the default behavior is for it to check a few locations
that all follow a similar naming convention, depending on platform.

In POSIX operating systems like any standard Linux distribution, the BSD's,
or if GNU ever finishes making an operating system, there are four total
places where your executable may be located.

- /usr/games
- /usr/local/games
- /usr/bin
- /usr/local/bin


Each of these locations corresponds to a "share" directory for shared data.

- /usr/share/games
- /usr/local/share/games
- /usr/share
- /usr/local/share


When your game is installed, you'll typically add a subdirectory, whose name
is expected to match the name of the executable.  So, for example, if your
distribution puts the binary in /usr/games, and your game executable is
"spaceinvaders", then you'll find your assets in /usr/share/games/spaceinvaders.

Additionally, there's always the possibility of a game being installed to
$HOME/.local/bin, in which case you have simply the prefix of $HOME/.local.
Cerritos can detect this configuration as well.

Meanwhile, in Windows, you're going to have a $PROGRAM FILES/spaceinvaders
directory in a location that's dependent on what version of Windows you're
using.  This directory will probably have an "assets" directory under it,
which is the default configuration of Path.

## Configuration Locations

Configuration is both simpler and different for no good reason.  In POSIX,
there are basically only two places config files are stored.  They are
"/etc" and $HOME/.yourprogramname.  Cerritos will look in /etc/yourprogramname
for siteconfig, and for config it'll look in $HOME/.yourprogramname.

In Windows, that same siteconfig will be in $PROGRAM FILES/yourprogramname/config.

## Other locations

Games usually ship with all assets they need and don't require the host
system to have any pre-installed.  This is different from applications,
where your word processor and web browser both expect there to be an
installed font library, for example.  However, Cerritos can still search
in system locations for system-installed assets that may be reasonably
expected to be found on your target system.  This behavior is disabled
by default and is specified by the third argument to _PATH.getFilepath.

Typically, this is where you'll be looking for fonts, system icons, and
system sound effects.  Cerritos doesn't provide any integration with your
operating system's theme engine, however, so it's really not reliable to
search in system directories.

## How to find directories in Cerritos

The following is a non-exhaustive list of directories Cerritos already
knows about and will find automatically.  In this list, the first part
is passed as a string to _PATH.getFilepath, as in _PATH.getFilepath("images", "myimage.png").

- share: /usr/share/games/yourprogramname/
- siteconfig: /etc/yourprogramname/
- userconfig: $HOME/.yourprogramname/
- images: "share"/images/
- sprites: "share"/sprites/
- fonts: "share"/fonts/
- sound: "share"/sounds/
- music: "share"/music/


Note that many of these paths are built from the same one.

## Customizing Paths

You don't have to accept the directory tree Cerritos supports by default.
The Path object is configurable.

@TODO: Write the rest of this.
