\page gettingstarted Getting Started

How to acquire and install cerritos.

\page helloworld Writing your first game with cerritos.

Let's talk about what a Hello, World! game looks like.

\page programmingstyle How to program a Cerritos game

There are three approaches to writing a game with Cerritos.  You can use
Cerritos as a complete out-of-the-box engine.  You can also write your
game completely from scratch.  You can also use a blended approach.

Regardless of which style you prefer, you will likely need to subclass
cApplication and cMainWindow.

# Styles

## From Scratch

When writing a game from scratch, that means you have to write your
main game loop, including the main() function in a C++ game.  If you come
from an SDL or SFML background, this is the style you're going to be
familiar with.

When working from scratch, you'll call all of the normally-internal
methods of cApplication and cMainWindow to make Cerritos do the work 
it's supposed to do, but you'll decide when they called.  This approach
is useful when you have things that need to be done when your timing is
different than Cerritos is expecting, or particularly if you're using
another helper library that doesn't work with Cerritos.

The standard game loop in a from scratch game goes roughly like this:

- Poll for events, typically hardware events and user input
- Process events.
- Simulate the game, typically the main body of the game logic.
- Render a frame


When using Cerritos from scratch, you'll need to implement it in some
form that has these steps, in this order:

- Call cApplication::BeginUpdate() to get all events queued up for processing.
- Loop through all queued events calling cApplication::pollEvent()
  to get each event from the queue.  You'll handle your own processing.
- Call cApplication::EndUpdate.


Consult cApplication documentation for more information.

## Out of the Box

When using Cerritos as an out of the box engine, you'll use one of the 
#CERRITOSMAIN(app, window) macros in place of the standard c main() function.  Typically,
you'll rely on Cerritos to do all of the work needed for your application,
and at least some of the work for your game.  For this style, you'll
need to implement most/all of the virtual methods in cApplication and
cMainWindow.  Here is a non-exhaustive list of these methods:

- cApplication::ProcessOneEvent will provide you only with events that
  were not consumed by the GUI.
- cApplication::Update this is where your application loop belongs.  You'll
  need to use a switch statement to determine where in your application
  you're at currently, whether it's the pregame GUI, in-game play, or
  whatever.  It's basically where your game simulation will reside.
- cMainWindow::Update is a catch-all place for you to update graphical
  things that don't have another place for updating.
- cMainWindow::Render is called before the GUI is rendered, but after
  the game screen has been rendered.


There are some other useful methods you'll need.

- cApplication::getTimestep will give you the current clock time so
  you can update animations and the simulation.

