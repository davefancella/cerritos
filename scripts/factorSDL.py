#!/usr/bin/env python3

# This script just takes a list of SDL variables with other crap and outputs
# a single list of only those variables

# Modify as needed when translating SDL enums to Cerritos enums

theString = '''
SDLK_0
SDLK_1
SDLK_2
SDLK_3
SDLK_4
SDLK_5
SDLK_6
SDLK_7
SDLK_8
SDLK_9
SDLK_a
SDLK_AC_BACK
SDLK_AC_BOOKMARKS
SDLK_AC_FORWARD
SDLK_AC_HOME
SDLK_AC_REFRESH
SDLK_AC_SEARCH
SDLK_AC_STOP
SDLK_AGAIN
SDLK_ALTERASE
SDLK_QUOTE
SDLK_APPLICATION
SDLK_AUDIOMUTE
SDLK_AUDIONEXT
SDLK_AUDIOPLAY
SDLK_AUDIOPREV
SDLK_AUDIOSTOP
SDLK_b
SDLK_BACKSLASH
SDLK_BACKSPACE
SDLK_BRIGHTNESSDOWN
SDLK_BRIGHTNESSUP
SDLK_c
SDLK_CALCULATOR
SDLK_CANCEL
SDLK_CAPSLOCK
SDLK_CLEAR
SDLK_CLEARAGAIN
SDLK_COMMA
SDLK_COMPUTER
SDLK_COPY
SDLK_CRSEL
SDLK_CURRENCYSUBUNIT
SDLK_CURRENCYUNIT
SDLK_CUT
SDLK_d
SDLK_DECIMALSEPARATOR
SDLK_DELETE
SDLK_DISPLAYSWITCH
SDLK_DOWN
SDLK_e
SDLK_EJECT
SDLK_END
SDLK_EQUALS
SDLK_ESCAPE
SDLK_EXECUTE
SDLK_EXSEL
SDLK_f
SDLK_F1
SDLK_F10
SDLK_F11
SDLK_F12
SDLK_F13
SDLK_F14
SDLK_F15
SDLK_F16
SDLK_F17
SDLK_F18
SDLK_F19
SDLK_F2
SDLK_F20
SDLK_F21
SDLK_F22
SDLK_F23
SDLK_F24
SDLK_F3
SDLK_F4
SDLK_F5
SDLK_F6
SDLK_F7
SDLK_F8
SDLK_F9
SDLK_FIND
SDLK_g
SDLK_BACKQUOTE
SDLK_h
SDLK_HELP
SDLK_HOME
SDLK_i
SDLK_INSERT
SDLK_j
SDLK_k
SDLK_KBDILLUMDOWN
SDLK_KBDILLUMTOGGLE
SDLK_KBDILLUMUP
SDLK_KP_0
SDLK_KP_00
SDLK_KP_000
SDLK_KP_1
SDLK_KP_2
SDLK_KP_3
SDLK_KP_4
SDLK_KP_5
SDLK_KP_6
SDLK_KP_7
SDLK_KP_8
SDLK_KP_9
SDLK_KP_A
SDLK_KP_AMPERSAND
SDLK_KP_AT
SDLK_KP_B
SDLK_KP_BACKSPACE
SDLK_KP_BINARY
SDLK_KP_C
SDLK_KP_CLEAR
SDLK_KP_CLEARENTRY
SDLK_KP_COLON
SDLK_KP_COMMA
SDLK_KP_D
SDLK_KP_DBLAMPERSAND
SDLK_KP_DECIMAL
SDLK_KP_DIVIDE
SDLK_KP_E
SDLK_KP_ENTER
SDLK_KP_EQUALS
SDLK_KP_EQUALSAS400
SDLK_KP_EXCLAM
SDLK_KP_F
SDLK_KP_GREATER
SDLK_KP_HASH
SDLK_KP_HEXADECIMAL
SDLK_KP_LEFTBRACE
SDLK_KP_LEFTPAREN
SDLK_KP_LESS

"Keypad MemAdd" (the Mem Add key (numeric keypad))

SDL_SCANCODE_KP_MEMADD

SDLK_KP_MEMADD

"Keypad MemClear" (the Mem Clear key (numeric keypad))

SDL_SCANCODE_KP_MEMCLEAR

SDLK_KP_MEMCLEAR

"Keypad MemDivide" (the Mem Divide key (numeric keypad))

SDL_SCANCODE_KP_MEMDIVIDE

SDLK_KP_MEMDIVIDE

"Keypad MemMultiply" (the Mem Multiply key (numeric keypad))

SDL_SCANCODE_KP_MEMMULTIPLY

SDLK_KP_MEMMULTIPLY

"Keypad MemRecall" (the Mem Recall key (numeric keypad))

SDL_SCANCODE_KP_MEMRECALL

SDLK_KP_MEMRECALL

"Keypad MemStore" (the Mem Store key (numeric keypad))

SDL_SCANCODE_KP_MEMSTORE

SDLK_KP_MEMSTORE

"Keypad MemSubtract" (the MemSubtract key (numeric keypad))

SDL_SCANCODE_KP_MEMSUBTRACT

SDLK_KP_MEMSUBTRACT

"Keypad -" (the 0-key (numeric keypad))

SDL_SCANCODE_KP_MINUS

SDLK_KP_MINUS

"Keypad *" (the * key (numeric keypad))

SDL_SCANCODE_KP_MULTIPLY

SDLK_KP_MULTIPLY

"Keypad Octal" (the Octal key (numeric keypad))

SDL_SCANCODE_KP_OCTAL

SDLK_KP_OCTAL

"Keypad %" (the Percent key (numeric keypad))

SDL_SCANCODE_KP_PERCENT

SDLK_KP_PERCENT

"Keypad ." (the . key (numeric keypad))

SDL_SCANCODE_KP_PERIOD

SDLK_KP_PERIOD

"Keypad +" (the + key (numeric keypad))

SDL_SCANCODE_KP_PLUS

SDLK_KP_PLUS

"Keypad +/-" (the +/- key (numeric keypad))

SDL_SCANCODE_KP_PLUSMINUS

SDLK_KP_PLUSMINUS

"Keypad ^" (the Power key (numeric keypad))

SDL_SCANCODE_KP_POWER

SDLK_KP_POWER

"Keypad }" (the Right Brace key (numeric keypad))

SDL_SCANCODE_KP_RIGHTBRACE

SDLK_KP_RIGHTBRACE

"Keypad )" (the Right Parenthesis key (numeric keypad))

SDL_SCANCODE_KP_RIGHTPAREN

SDLK_KP_RIGHTPAREN

"Keypad Space" (the Space key (numeric keypad))

SDL_SCANCODE_KP_SPACE

SDLK_KP_SPACE

"Keypad Tab" (the Tab key (numeric keypad))

SDL_SCANCODE_KP_TAB

SDLK_KP_TAB

"Keypad |" (the | key (numeric keypad))

SDL_SCANCODE_KP_VERTICALBAR

SDLK_KP_VERTICALBAR

"Keypad XOR" (the XOR key (numeric keypad))

SDL_SCANCODE_KP_XOR

SDLK_KP_XOR

"L"

SDL_SCANCODE_L

SDLK_l

"Left Alt"

SDL_SCANCODE_LALT

SDLK_LALT

"Left Ctrl"

SDL_SCANCODE_LCTRL

SDLK_LCTRL

"Left" (the Left arrow key (navigation keypad))

SDL_SCANCODE_LEFT

SDLK_LEFT

"["

SDL_SCANCODE_LEFTBRACKET

SDLK_LEFTBRACKET

"Left GUI" (windows, command (apple), meta)

SDL_SCANCODE_LGUI

SDLK_LGUI

"Left Shift"

SDL_SCANCODE_LSHIFT

SDLK_LSHIFT

"M"

SDL_SCANCODE_M

SDLK_m

"Mail" (the Mail/eMail key)

SDL_SCANCODE_MAIL

SDLK_MAIL

"MediaSelect" (the Media Select key)

SDL_SCANCODE_MEDIASELECT

SDLK_MEDIASELECT

"Menu"

SDL_SCANCODE_MENU

SDLK_MENU

"-"

SDL_SCANCODE_MINUS

SDLK_MINUS

"ModeSwitch"

SDL_SCANCODE_MODE

SDLK_MODE

"Mute"

SDL_SCANCODE_MUTE

SDLK_MUTE

"N"

SDL_SCANCODE_N

SDLK_n

"Numlock" (the Num Lock key (PC) / the Clear key (Mac))

SDL_SCANCODE_NUMLOCKCLEAR

SDLK_NUMLOCKCLEAR

"O"

SDL_SCANCODE_O

SDLK_o

"Oper"

SDL_SCANCODE_OPER

SDLK_OPER

"Out"

SDL_SCANCODE_OUT

SDLK_OUT

"P"

SDL_SCANCODE_P

SDLK_p

"PageDown"

SDL_SCANCODE_PAGEDOWN

SDLK_PAGEDOWN

"PageUp"

SDL_SCANCODE_PAGEUP

SDLK_PAGEUP

"Paste"

SDL_SCANCODE_PASTE

SDLK_PASTE

"Pause" (the Pause / Break key)

SDL_SCANCODE_PAUSE

SDLK_PAUSE

"."

SDL_SCANCODE_PERIOD

SDLK_PERIOD

"Power" (The USB document says this is a status flag, not a physical key - but some Mac keyboards do have a power key.)

SDL_SCANCODE_POWER

SDLK_POWER

"PrintScreen"

SDL_SCANCODE_PRINTSCREEN

SDLK_PRINTSCREEN

"Prior"

SDL_SCANCODE_PRIOR

SDLK_PRIOR

"Q"

SDL_SCANCODE_Q

SDLK_q

"R"

SDL_SCANCODE_R

SDLK_r

"Right Alt" (alt gr, option)

SDL_SCANCODE_RALT

SDLK_RALT

"Right Ctrl"

SDL_SCANCODE_RCTRL

SDLK_RCTRL

"Return" (the Enter key (main keyboard))

SDL_SCANCODE_RETURN

SDLK_RETURN

"Return"

SDL_SCANCODE_RETURN2

SDLK_RETURN2

"Right GUI" (windows, command (apple), meta)

SDL_SCANCODE_RGUI

SDLK_RGUI

"Right" (the Right arrow key (navigation keypad))

SDL_SCANCODE_RIGHT

SDLK_RIGHT

"]"

SDL_SCANCODE_RIGHTBRACKET

SDLK_RIGHTBRACKET

"Right Shift"

SDL_SCANCODE_RSHIFT

SDLK_RSHIFT

"S"

SDL_SCANCODE_S

SDLK_s

"ScrollLock"

SDL_SCANCODE_SCROLLLOCK

SDLK_SCROLLLOCK

"Select"

SDL_SCANCODE_SELECT

SDLK_SELECT

";"

SDL_SCANCODE_SEMICOLON

SDLK_SEMICOLON

"Separator"

SDL_SCANCODE_SEPARATOR

SDLK_SEPARATOR

"/"

SDL_SCANCODE_SLASH

SDLK_SLASH

"Sleep" (the Sleep key)

SDL_SCANCODE_SLEEP

SDLK_SLEEP

"Space" (the Space Bar key(s))

SDL_SCANCODE_SPACE

SDLK_SPACE

"Stop"

SDL_SCANCODE_STOP

SDLK_STOP

"SysReq" (the SysReq key)

SDL_SCANCODE_SYSREQ

SDLK_SYSREQ

"T"

SDL_SCANCODE_T

SDLK_t

"Tab" (the Tab key)

SDL_SCANCODE_TAB

SDLK_TAB

"ThousandsSeparator" (the Thousands Separator key)

SDL_SCANCODE_THOUSANDSSEPARATOR

SDLK_THOUSANDSSEPARATOR

"U"

SDL_SCANCODE_U

SDLK_u

"Undo"

SDL_SCANCODE_UNDO

SDLK_UNDO

"" (no name, empty string)

SDL_SCANCODE_UNKNOWN

SDLK_UNKNOWN

"Up" (the Up arrow key (navigation keypad))

SDL_SCANCODE_UP

SDLK_UP

"V"

SDL_SCANCODE_V

SDLK_v

"VolumeDown"

SDL_SCANCODE_VOLUMEDOWN

SDLK_VOLUMEDOWN

"VolumeUp"

SDL_SCANCODE_VOLUMEUP

SDLK_VOLUMEUP

"W"

SDL_SCANCODE_W

SDLK_w

"WWW" (the WWW/World Wide Web key)

SDL_SCANCODE_WWW

SDLK_WWW

"X"

SDL_SCANCODE_X

SDLK_x

"Y"

SDL_SCANCODE_Y

SDLK_y

"Z"

SDL_SCANCODE_Z

SDLK_z

These physical keys do not have corresponding virtual key values

"" (no name, empty string; used on Asian keyboards, see footnotes in USB doc)

SDL_SCANCODE_INTERNATIONAL1

(none)

"" (no name, empty string)

SDL_SCANCODE_INTERNATIONAL2

(none)

"" (no name, empty string; Yen)

SDL_SCANCODE_INTERNATIONAL3

(none)

"" (no name, empty string)

SDL_SCANCODE_INTERNATIONAL4

(none)

"" (no name, empty string)

SDL_SCANCODE_INTERNATIONAL5

(none)

"" (no name, empty string)

SDL_SCANCODE_INTERNATIONAL6

(none)

"" (no name, empty string)

SDL_SCANCODE_INTERNATIONAL7

(none)

"" (no name, empty string)

SDL_SCANCODE_INTERNATIONAL8

(none)

"" (no name, empty string)

SDL_SCANCODE_INTERNATIONAL9

(none)

"" (no name, empty string; Hangul/English toggle)

SDL_SCANCODE_LANG1

(none)

"" (no name, empty string; Hanja conversion)

SDL_SCANCODE_LANG2

(none)

"" (no name, empty string; Katakana)

SDL_SCANCODE_LANG3

(none)

"" (no name, empty string; Hiragana)

SDL_SCANCODE_LANG4

(none)

"" (no name, empty string; Zenkaku/Hankaku)

SDL_SCANCODE_LANG5

(none)

"" (no name, empty string; reserved)

SDL_SCANCODE_LANG6

(none)

"" (no name, empty string; reserved)

SDL_SCANCODE_LANG7

(none)

"" (no name, empty string; reserved)

SDL_SCANCODE_LANG8

(none)

"" (no name, empty string; reserved)

SDL_SCANCODE_LANG9

(none)

"" (no name, empty string)

SDL_SCANCODE_LOCKINGCAPSLOCK

(none)

"" (no name, empty string)

SDL_SCANCODE_LOCKINGNUMLOCK

(none)

"" (no name, empty string)

SDL_SCANCODE_LOCKINGSCROLLLOCK

(none)

"" (no name, empty string; This is the additional key that ISO keyboards have over ANSI ones, located between left shift and Y. Produces GRAVE ACCENT and TILDE in a US or UK Mac layout, REVERSE SOLIDUS (backslash) and VERTICAL LINE in a US or UK Windows layout, and LESS-THAN SIGN and GREATER-THAN SIGN in a Swiss German, German, or French layout.)

SDL_SCANCODE_NONUSBACKSLASH

(none)

"#" (ISO USB keyboards actually use this code instead of 49 for the same key, but all OSes I've seen treat the two codes identically. So, as an implementor, unless your keyboard generates both of those codes and your OS treats them differently, you should generate SDL_SCANCODE_BACKSLASH instead of this code. As a user, you should not rely on this code because SDL will never generate it with most (all?) keyboards.)

SDL_SCANCODE_NONUSHASH

(none)

These virtual key values do not have corresponding physical keys

"&"

(none)

SDLK_AMPERSAND

"*"

(none)

SDLK_ASTERISK

"@"

(none)

SDLK_AT

"^"

(none)

SDLK_CARET

":"

(none)

SDLK_COLON

"$"

(none)

SDLK_DOLLAR

"!"

(none)

SDLK_EXCLAIM

">"

(none)

SDLK_GREATER

"#"

(none)

SDLK_HASH

"("

(none)

SDLK_LEFTPAREN

"<"

(none)

SDLK_LESS

"%"

(none)

SDLK_PERCENT

"+"

(none)

SDLK_PLUS

"?"

(none)

SDLK_QUESTION

"""

(none)

SDLK_QUOTEDBL

")"

(none)

SDLK_RIGHTPAREN

"_"

(none)

SDLK_UNDERSCORE
'''
maxLength = 0

for a in theString.split():
    a = a.strip()
    
    if len(a) == 0: continue

    if len(a[3:]) > maxLength:
        maxLength = len(a[3:])
    
    if a.startswith("SDLK"):
        cerName = a[3:]
        # f'    {cerName:30} = {a}'
        print(f'    {cerName},')
#print(maxLength)
