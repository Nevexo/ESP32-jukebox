# ESP32-Jukebox

> Note: This project is very much experimental
> This is one of the first PCBs I've designed, so is likely poorly done!
> This is primarily a learning experience, and not in any way a final product.

This project aims to create a Minecraft-style Jukebox based on:

- ESP32-S3 (MCU)
- MAX98357A (DAC/Class-D amplifier)
- PN532 (NFC)

The device will take "discs" (3D printed cards with embedded NTAG NFC stickers) and play a jukebox track
from an SD card.

## Implementation Notes

### NFC (PN532)
As this is one of my first PCB designs, I'm not at all confident in my ability to design an NFC coil...

This project will instead use a generic PN532 development board connected via I2C, the board will have a P-Channel MOSFET to cut power
to this board when it's not in use, as it has onboard LEDs and is not designed for power efficiency.

### SD Card
Similar to the PN532 module, the SD card will be high-side power switched when the ESP32 goes to sleep.

### MAX98357A
The MAX98357A class-D amplifier/DAC has a built in shutdown mode, this will be asserted whenever the PlaybackActive bit isn't set.

## CAD
The CAD work will be done in OnShape: [Onshape Link]

## Firmware
The firmware will be based on ESP-IDF.

## Planned Features
- [ ] NFC Tag Reading
- [ ] SD Card FS Mounting/Reading
- [ ] WAV header reading
- [ ] Audio Playback
- [ ] Power management etc.

### Remote Control
This device won't have any user-facing buttons to keep it as similar to the Minecraft jukebox as possible. Because of that, I'm considering using Bluetooth LE as a configuration interface,
so a device running some kind of app (or just nRF Connect) can alter the settings on the device when a "configuration disc" is inserted.
