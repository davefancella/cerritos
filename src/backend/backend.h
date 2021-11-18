/*
 * Cerritos
 * Copyright 2021 by Dave Fancella, Anthony Fancella
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 * 
 */

// This is the file where all the translations from backend to cerritos
// should occur.

#ifndef BACKEND__H
#define BACKEND__H

#include <stdint.h>

#include "string.h"

class cWindow;
class cEventManager;

// These are the functions a backend must implement

// Clock
unsigned int GetTicks();

// Just delay code execution, equivalent to sleep()
void Delay(unsigned int ms);

// Initialize the backend
int backendInit();
void backendClose();

// Poll backend for hardware events and put them in the event manager
void PollHardwareEvents(cEventManager* eventManager);

// All the stuff needed to work with surfaces

// This is a forward declaration.  Typically, you'll define this in
// your backend.  Currently, these are just placeholders for SDL stuff.
struct cSurfaceS;
struct cRect;
struct cPixelFormat;
//struct cWindow;

const char* GetError();

unsigned int MapRGB(cPixelFormat* format,
                  uint8_t r, uint8_t g, uint8_t b);

inline cSurfaceS* CreateRGBSurface();
int CreateRGBSurfaceFrom();
int FillRects();
int FreeSurface();
int GetClipRect();
int GetColorKey();
int GetSurfaceAlphaMod();
int GetSurfaceBlendMode();
int GetSurfaceColorMod();
int LoadBMP_RW();
int LockSurface();
int LowerBlit();
int MUSTLOCK();
int SaveBMP_RW();
int SetClipRect();
int SetColorKey();
int SetSurfaceAlphaMod();
int SetSurfaceBlendMode();
int SetSurfaceColorMod();
int SetSurfacePalette();
int SetSurfaceRLE();
int SoftStretch();
int UnlockSurface();

// These are the enums that a backend must provide

/* Window flags
typedef enum {
    CER_Fullscreen, CER_FullDesktop, CER_OpenGl, CER_Vulkan, CER_Shown, CER_Hidden,
    CER_Borderless, CER_Resizable, CER_Minimized, CER_Maximized, CER_GrabInput, CER_FocusInput,
    CER_FocusMouse, CER_Foreign, CER_HighDpi, CER_CaptureMouse, CER_AlwaysOnTop,
    CER_NoTaskbar, CER_Utility, CER_Tooltip, CER_PopupMenu,
    CER_WindowPos_Centered, CER_WindowPos_Undefined
} CER_WindowFlags;
*/

/* Keycodes, used for input
typedef enum {
    K_0,
    K_1,
    K_2,
    K_3,
    K_4,
    K_5,
    K_6,
    K_7,
    K_8,
    K_9,
    K_a,
    K_AC_BACK,
    K_AC_BOOKMARKS,
    K_AC_FORWARD,
    K_AC_HOME,
    K_AC_REFRESH,
    K_AC_SEARCH,
    K_AC_STOP,
    K_AGAIN,
    K_ALTERASE,
    K_QUOTE,
    K_APPLICATION,
    K_AUDIOMUTE,
    K_AUDIONEXT,
    K_AUDIOPLAY,
    K_AUDIOPREV,
    K_AUDIOSTOP,
    K_b,
    K_BACKSLASH,
    K_BACKSPACE,
    K_BRIGHTNESSDOWN,
    K_BRIGHTNESSUP,
    K_c,
    K_CALCULATOR,
    K_CANCEL,
    K_CAPSLOCK,
    K_CLEAR,
    K_CLEARAGAIN,
    K_COMMA,
    K_COMPUTER,
    K_COPY,
    K_CRSEL,
    K_CURRENCYSUBUNIT,
    K_CURRENCYUNIT,
    K_CUT,
    K_d,
    K_DECIMALSEPARATOR,
    K_DELETE,
    K_DISPLAYSWITCH,
    K_DOWN,
    K_e,
    K_EJECT,
    K_END,
    K_EQUALS,
    K_ESCAPE,
    K_EXECUTE,
    K_EXSEL,
    K_f,
    K_F1,
    K_F10,
    K_F11,
    K_F12,
    K_F13,
    K_F14,
    K_F15,
    K_F16,
    K_F17,
    K_F18,
    K_F19,
    K_F2,
    K_F20,
    K_F21,
    K_F22,
    K_F23,
    K_F24,
    K_F3,
    K_F4,
    K_F5,
    K_F6,
    K_F7,
    K_F8,
    K_F9,
    K_FIND,
    K_g,
    K_BACKQUOTE,
    K_h,
    K_HELP,
    K_HOME,
    K_i,
    K_INSERT,
    K_j,
    K_k,
    K_KBDILLUMDOWN,
    K_KBDILLUMTOGGLE,
    K_KBDILLUMUP,
    K_KP_0,
    K_KP_00,
    K_KP_000,
    K_KP_1,
    K_KP_2,
    K_KP_3,
    K_KP_4,
    K_KP_5,
    K_KP_6,
    K_KP_7,
    K_KP_8,
    K_KP_9,
    K_KP_A,
    K_KP_AMPERSAND,
    K_KP_AT,
    K_KP_B,
    K_KP_BACKSPACE,
    K_KP_BINARY,
    K_KP_C,
    K_KP_CLEAR,
    K_KP_CLEARENTRY,
    K_KP_COLON,
    K_KP_COMMA,
    K_KP_D,
    K_KP_DBLAMPERSAND,
    K_KP_DECIMAL,
    K_KP_DIVIDE,
    K_KP_E,
    K_KP_ENTER,
    K_KP_EQUALS,
    K_KP_EQUALSAS400,
    K_KP_EXCLAM,
    K_KP_F,
    K_KP_GREATER,
    K_KP_HASH,
    K_KP_HEXADECIMAL,
    K_KP_LEFTBRACE,
    K_KP_LEFTPAREN,
    K_KP_LESS,
    K_KP_MEMADD,
    K_KP_MEMCLEAR,
    K_KP_MEMDIVIDE,
    K_KP_MEMMULTIPLY,
    K_KP_MEMRECALL,
    K_KP_MEMSTORE,
    K_KP_MEMSUBTRACT,
    K_KP_MINUS,
    K_KP_MULTIPLY,
    K_KP_OCTAL,
    K_KP_PERCENT,
    K_KP_PERIOD,
    K_KP_PLUS,
    K_KP_PLUSMINUS,
    K_KP_POWER,
    K_KP_RIGHTBRACE,
    K_KP_RIGHTPAREN,
    K_KP_SPACE,
    K_KP_TAB,
    K_KP_VERTICALBAR,
    K_KP_XOR,
    K_l,
    K_LALT,
    K_LCTRL,
    K_LEFT,
    K_LEFTBRACKET,
    K_LGUI,
    K_LSHIFT,
    K_m,
    K_MAIL,
    K_MEDIASELECT,
    K_MENU,
    K_MINUS,
    K_MODE,
    K_MUTE,
    K_n,
    K_NUMLOCKCLEAR,
    K_o,
    K_OPER,
    K_OUT,
    K_p,
    K_PAGEDOWN,
    K_PAGEUP,
    K_PASTE,
    K_PAUSE,
    K_PERIOD,
    K_POWER,
    K_PRINTSCREEN,
    K_PRIOR,
    K_q,
    K_r,
    K_RALT,
    K_RCTRL,
    K_RETURN,
    K_RETURN2,
    K_RGUI,
    K_RIGHT,
    K_RIGHTBRACKET,
    K_RSHIFT,
    K_s,
    K_SCROLLLOCK,
    K_SELECT,
    K_SEMICOLON,
    K_SEPARATOR,
    K_SLASH,
    K_SLEEP,
    K_SPACE,
    K_STOP,
    K_SYSREQ,
    K_t,
    K_TAB,
    K_THOUSANDSSEPARATOR,
    K_u,
    K_UNDO,
    K_UNKNOWN,
    K_UP,
    K_v,
    K_VOLUMEDOWN,
    K_VOLUMEUP,
    K_w,
    K_WWW,
    K_x,
    K_y,
    K_z,
    K_AMPERSAND,
    K_ASTERISK,
    K_AT,
    K_CARET,
    K_COLON,
    K_DOLLAR,
    K_EXCLAIM,
    K_GREATER,
    K_HASH,
    K_LEFTPAREN,
    K_LESS,
    K_PERCENT,
    K_PLUS,
    K_QUESTION,
    K_QUOTEDBL,
    K_RIGHTPAREN,
    K_UNDERSCORE,
} CER_Keycode;
*/

#include "sdl_backend.h"

#endif // BACKEND__H


