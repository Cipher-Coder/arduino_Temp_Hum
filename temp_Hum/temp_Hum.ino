#include "Arduino.h"
#include "LiquidCrystal.h"
#include "DHT.h"
//The setup function is called once at startup of the sketch

//Set the DHT Pin
#define DHTPIN 8
//Initialize the library with he numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
//Setup the LCD's number of columns and rows:
  lcd.begin(16, 2);
  dht.begin();
//Print a message to the LCD
  lcd.print("Temp:  Humidity:");
}

// The loop function is called in an endless loop
void loop()
{
  delay(500);
//Set cursor to column 0, line 1(actually 2nd row)
  lcd.setCursor(0, 1);
  //Read humidity
  float h = dht.readHumidity();
  //read temp in fahrenheit
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(f)) {
	  lcd.print("ERROR");
	  return;
  }
  lcd.print(f);
  lcd.setCursor(7, 1);
  lcd.print(h);

}
