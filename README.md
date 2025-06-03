# EspLedLyrics Project

Hey folks, welcome to EspLedLyrics! This is a simple ESP32 sketch for displaying lyrics on a 128x64 OLED display. I threw this together after messing around with some Arduino stuff—it's based on that classic SSD1306 setup. If you're into DIY LED projects or just want to show off some text on a screen, this might be a fun starting point. I've seen a bunch of people on forums adapt it for their own lyrics or messages.

## What This Does
This code makes an OLED screen cycle through a set of lyrics (like a little song snippet). It's super basic, but it's a great way to learn about I2C displays and Arduino libraries. One user on a Discord server mentioned using it to display quotes from their favorite bands—cool idea!

## Requirements
Before you dive in, make sure you've got:
- **Hardware:**
  - An ESP32 board (I tested this on a standard ESP32 DevKit).
  - A 128x64 SSD1306 OLED display connected via I2C (SDA on GPIO21, SCL on GPIO22 by default).
  - Jumper wires and a breadboard for hooking it up.
- **Software:**
  - Arduino IDE (latest version—grab it from the official site).
  - The U8g2 library installed via the Library Manager.
  - PlatformIO or a similar setup if you're not using plain Arduino (some folks swear by it for ESP32 projects).

## How to Set It Up
Getting this running is pretty straightforward—here's how I did it, based on tips from a few Reddit threads:

1. **Clone or Download the Repo:**
   - Grab the files from here (or just use what you've got). Put them in a folder like `EspLedLyrics`.

2. **Install Dependencies:**
   - Open Arduino IDE.
   - Go to Sketch > Include Library > Manage Libraries, and search for "U8g2". Install the latest version.
   - Also, make sure your board is set up: In Arduino IDE, go to Tools > Board > ESP32 > [Your ESP32 model].

3. **Wire It Up:**
   - Connect the OLED to your ESP32:
     - OLED VCC to 3.3V on ESP32.
     - OLED GND to GND.
     - OLED SDA to GPIO21.
     - OLED SCL to GPIO22.
   - Double-check your connections—I've fried a board before by mixing up pins, so take it slow!

4. **Upload the Code:**
   - Open `src/main.cpp` in Arduino IDE.
   - Select the right board and port (Tools > Port).
   - Hit Upload. If it works, you should see "OLED Hello World test" in the Serial Monitor at 115200 baud.

## How to Use It
Once it's uploaded, the code will loop through a sequence of lyrics on the OLED screen. Each line shows for about 1.8 seconds, then it waits 5 seconds before starting over. Pretty simple, but here's where the fun begins:

- **Customizing the Lyrics:**
  - In `src/main.cpp`, look at the `loop()` function. That's where the magic happens—it's just a series of calls to `displaySingleLine()`. Swap out the strings like "MADE BY TEBE" with your own text. One guy on a forum said he made it display song lyrics synced to music—neat hack if you're into that.

- **Tweak the Timing:**
  - If you want faster or slower displays, change the `delay(1800)` in `displaySingleLine()` or `delay(5000)` in `loop()`. Keep in mind, too many delays can make your code feel unresponsive, so some people suggest using timers instead for better performance.

## Community Notes and Tips
This is where things get chatty—like we're all hanging out in a programming Discord. A few users have shared their experiences:

- **Common Tweaks:** If you're displaying longer text, you might need to adjust the font in `displaySingleLine()`. Someone on Stack Overflow suggested trying `u8g2_font_ncenB14_tr` for bigger text—it fits more on screen without messing up the layout.
  
- **Troubleshooting:** If the display doesn't show up, check your I2C connections first. One person fixed theirs by adding a pull-up resistor—apparently, ESP32 I2C can be finicky. Also, if Serial output looks weird, ensure your baud rate matches.

- **Ideas for Expansion:** Ever thought about adding buttons to skip lines? You could hook into the `loop()` function and use interrupts for that. It's a bit more advanced, but it's a popular discussion point—keeps the code from getting too nested and messy.

If you've got your own mods or issues, drop a comment or start a thread somewhere. Let's keep this project alive!

Happy coding, everyone!
