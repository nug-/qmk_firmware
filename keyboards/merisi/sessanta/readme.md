# Merisi Sessanta

![Merisi Sessanta](https://merisi.works)

This is the 60% PCB for the Merisi Sessanta. It has options for split Backspace and split right Shift.
The bottom row is 1.5u, 1u, 1.5u, 7u, 1.5u, 1u, 1.5u. The PCB uses soldered MX switches and an STM32F072RBT6.
A 4-pin JST cable connects the PCB to a USB-C daughterboard.

* Keyboard maintainer: Merisi Works
* Hardware supported: Merisi Sessanta PCB
* Hardware availability: [Merisi Works](https://merisi.works)

Make example for this keyboard (after setting up your build environment):

    make merisi/sessanta:default

Flashing example for this keyboard:

    make merisi/sessanta:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the
[make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new
to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Layouts

`LAYOUT_60_ansi_tsangan_split_bs_rshift` has all switch positions. The right half of the split Backspace is `` ` ``.
The 1u right half of the split right Shift is Fn (`MO(1)`).

`LAYOUT_60_ansi_tsangan` is for a 2u Backspace and a 2.75u right Shift. The two layouts are QMK community layouts.

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down Esc and connect the keyboard. This also erases the saved settings.
* **Physical reset button**: Push the RESET button on the PCB for a short time.
* **Keycode in layout**: Push the key that has `QK_BOOT`, if the keymap has this key.

The computer then shows the board as "STM32 BOOTLOADER" (`0483:df11`). The STM32 bootloader is in ROM.
Thus the RESET button operates with all firmware on the chip.

## Tutorials

The [Merisi QMK README](https://github.com/packman86/merisi-qmk#flash-the-merisi-sessanta) has two animations:

* [Flash the firmware with QMK Toolbox](https://github.com/packman86/merisi-qmk#flash-the-merisi-sessanta)
* [Add the Sessanta to VIA](https://github.com/packman86/merisi-qmk#use-via)
