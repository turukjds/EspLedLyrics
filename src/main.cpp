#include <Arduino.h>
#include <U8g2lib.h> // Include the U8g2 library
#include <Wire.h>

// Constructor for a common 128x64 I2C OLED (SSD1306)
// U8G2_R0 means no rotation
// U8X8_PIN_NONE means no reset pin is used (common for these modules)
// This uses hardware I2C, which defaults to SDA=GPIO21, SCL=GPIO22 on ESP32
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  Serial.begin(115200);
  while (!Serial); // Wait for serial port to connect.
  Serial.println("OLED Hello World test");

  u8g2.begin(); // Initialize the U8g2 library
  Serial.println("U8g2 initialized.");
}

// Helper function to display a single line of text
void displaySingleLine(const char* text, int y_pos = 25) { // y_pos for the baseline of the text
  u8g2.clearBuffer(); // Clear the internal memory of the display
  u8g2.setFont(u8g2_font_ncenB08_tr); // Choose a suitable font
  u8g2.drawStr(0, y_pos, text); // Draw the string
  u8g2.sendBuffer(); // Send the internal memory to the display
  
  Serial.print("Displaying on OLED: ");
  Serial.println(text);
  delay(1800); // Wait 1.8 seconds (adjust as needed)
}

void loop(void) {
  displaySingleLine("MADE BY TEBE");
  displaySingleLine("sudah terbiasa");
  displaySingleLine("terjadi tanteeee");
  displaySingleLine("teman datang ketika lagi");
  displaySingleLine("butuh sajaaaa");
  displaySingleLine("coba kalo lagi");
  displaySingleLine("susahhhh");
  displaySingleLine("mereka semua");
  displaySingleLine("menghilanggggggg");
  displaySingleLine("based on true story");

  Serial.println("Lyric sequence complete. Repeating in 5 seconds.");
  delay(5000); // Wait 5 seconds before repeating the whole sequence
}