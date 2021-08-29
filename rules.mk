BOOTLOADER = atmel-dfu

BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality on B7 by default
MIDI_ENABLE = no            # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
EXTRAKEY_ENABLE = yes       # Audio control and System control
TAP_DANCE_ENABLE = no      # Dance keyboard DANCE!
 
DEFAULT_FOLDER = atreus/promicro

SRC += joshckb/joshckb.c
SRC += joshckb/os_mode_utils.c

#SRC += ws2812.c
#SRC += led_cluster.c
