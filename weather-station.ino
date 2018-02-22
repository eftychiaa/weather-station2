//https://el.wikipedia.org/wiki/I%C2%B2C
//

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>

dht DHT;
#define DHT11_PIN 7

//Photoresistor
int lightSensorPin = A0;
int analogValue = 0;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  // initialize the LCD
  lcd.begin();

  // Turn on the backlight
  lcd.setBacklight(HIGH);

}

void loop()
{
  //photoresistor read
   analogValue=analogRead(lightSensorPin);
  //temp&hum read and display
  DHT.read11(DHT11_PIN);
  lcd.print("Temp:");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");

  Serial.print("Temperature:");
  Serial.print(DHT.temperature);
  Serial.print("C ");

  // Second row
  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.print(DHT.humidity);

  Serial.print("Humidity:");
  Serial.println(DHT.humidity);

   if(analogValue>25){
     lcd.print("  DAY  ");
  }else{
    lcd.print("  NIGHT");
  }

//photoresistor serial display
  Serial.print("The photoresistor value is ");
  Serial.print(analogValue);
  if(analogValue>25){
      Serial.println(" and it's daytime!");
   }else{
      Serial.println(" and it's nighttime!");
  }
  
  delay(1000);
  lcd.setCursor(0, 0);

}


