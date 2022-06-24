/*
Copyright 2021 Paul Schauppner <pschauppner@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0007
#define DEVICE_VER 		0x0001
#define MANUFACTURER    none
#define PRODUCT         ElevenFingers

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

/* ElevenFingers PCB default pin-out */
#define MATRIX_ROW_PINS { F7, B1, B3, B2, B6}
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5}
#define ENCODERS_PAD_A {F5}
#define ENCODERS_PAD_B {F6}
#define UNUSED_PINS

/* ws2812 RGB LED */
//#define RGB_DI_PIN F7

//#define RGBLED_NUM 1    // Number of LEDs

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 200

#define LEADER_TIMEOUT 500
#define LEADER_PER_KEY_TIMING

#define SPLIT_USB_DETECT
#define MASTER_LEFT
//for serial
#define SOFT_SERIAL_PIN D2
#define SELECT_SOFT_SERIAL_SPEED 5
//for i2c
//#define USE_I2C
//#define RIGHT_HALF_INT_I2C_PULLUPS_OFF

#endif
