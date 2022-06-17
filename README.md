# ElevenFingers
An ergonomic split keyboard

## Issues and planned work
- Bluetooth is tempermental with pull down resistors - no longer needed for my current setup - plan to remove
- Source code has to get modified for flashing left half and right half - not great
- some software layout issues (no semi colon, tilde, grave, function keys...) - could really expand on use of layers
- OLED can be more helpful
- I don't like the sound of clicky keys - plan to switch to tactile
- hotswap sockets were a bad idea - they made connections less reliable (and I'm not a big keyswapper anyway)
- Next: case + PCB, better wires
- a power switch, and/or a reset button might be nice

## Project Navigation

### keyboard-layout-editor
This folder contains the json for uploading in the 'Raw Data' tab of [keyboard-layout-editor.com](http://www.keyboard-layout-editor.com/)
It's rotated right because it was easier for dealing with a columnar stagger this way (keyboard-layout-editor syntax is row-based, assuming each "row" is at the same vertical offset).

### qmk_firmware/keyboards/ElevenFingers
Contains the source code that would go under 'keyboards' in the qmk_firmware root directory (https://github.com/qmk/qmk_firmware)

Note - my idea is that any customizations to qmk will be added here with a script to copy it into the qmk repository.  (Why does QMK host so many individual keyboard source files?)

### fabrication
This keyboard is currently a cardboard prototype.  The svg was used as a template to cutout squares in a piece of cardboard.  In the future this will contain drawings for case and mounting plates.  Note I used http://builder.swillkb.com/ with the MX switch type (and otherwise default settings) to generate this SVG.

### circuitry
This keyboard was handwired.  This folder contains notes and pictures of the wiring.  In the future, this will contain PCB design files.

