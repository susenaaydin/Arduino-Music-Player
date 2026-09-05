# Arduino-Music-Player
Arduino-based music player with LCD lyrics display, buzzer audio output, and note-based LED indicators.
# Arduino Music Player

An Arduino-based music player that combines melody playback, an LCD lyrics display, and LED indicators for musical notes.

## Features

* Plays predefined melodies using a buzzer
* Displays lyrics on a 16x2 LCD
* Lights up LEDs according to the played musical notes
* Supports different musical notes and octaves
* Controls note duration and tempo
* Displays the song title when the program starts

## Hardware

* Arduino
* 16x2 LCD
* Buzzer
* 7 LEDs
* Jumper wires
* Breadboard

## Pin Configuration

| Component | Pin |
| --------- | --- |
| LCD RS    | 12  |
| LCD E     | 11  |
| LCD D4    | A0  |
| LCD D5    | A1  |
| LCD D6    | A2  |
| LCD D7    | A3  |
| Note LEDs | 2–8 |
| Buzzer    | 9   |

## How It Works

The program defines the frequencies of musical notes and uses the Arduino `tone()` function to generate the corresponding sounds.

When a note is played, the LED associated with that note is activated. At the same time, the lyrics are displayed on the LCD according to the current part of the melody.

The playback tempo is calculated using BPM, and different note durations are used to control the rhythm.

## Technologies

* Arduino
* C/C++
* Arduino LiquidCrystal Library

## Project Status

Completed
