# Arduino Music Player

An Arduino-based music player project that plays melodies through a buzzer, displays lyrics on a 16x2 LCD screen, and controls LEDs according to the notes being played.

## Features

* 🎵 Plays predefined melodies using a buzzer
* 🎶 Supports different musical notes and octaves
* 📺 Displays lyrics on a 16x2 LCD screen
* 💡 Controls LEDs according to the notes being played
* ⏱️ Controls note durations and tempo
* 🎼 Controls rhythm based on BPM values
* 📝 Displays the song title when the program starts

## Hardware

* Arduino
* 16x2 LCD display
* Buzzer
* 7 LEDs
* Breadboard
* Jumper wires

## Pin Configuration

| Component | Arduino Pin |
| --------- | ----------: |
| LCD RS    |          12 |
| LCD E     |          11 |
| LCD D4    |          A0 |
| LCD D5    |          A1 |
| LCD D6    |          A2 |
| LCD D7    |          A3 |
| Note LEDs |         2–8 |
| Buzzer    |           9 |

## How It Works

The program defines the frequencies of different musical notes. Arduino's `tone()` function is then used to generate the corresponding sounds through the buzzer.

When a note is played, the LED corresponding to that note is activated. At the same time, the relevant lyrics from the melody are displayed on the LCD screen.

The melody tempo is determined using the BPM value. Different note durations are used to control the rhythm and playback speed.

## Technologies

* **Arduino**
* **C/C++**
* **Arduino LiquidCrystal Library**

## Project Purpose

The purpose of this project is to develop an Arduino application that combines sound generation, LCD display output, and LED control.

The project provides practical experience with:

* Generating sound using a buzzer
* Working with an LCD display
* Controlling LEDs
* Using musical note frequencies
* Managing note durations and tempo
* Integrating multiple hardware components

## Project Status

**Completed**

## Future Improvements

* Adding multiple songs
* Selecting songs using buttons
* Volume control
* Adding more LEDs for additional notes
* Creating a menu system
* Allowing users to create custom melodies

## Author

**Sude Sena Aydın**
