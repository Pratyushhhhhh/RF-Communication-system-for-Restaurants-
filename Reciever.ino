#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#include <LiquidCrystal.h>

RH_ASK driver;
LiquidCrystal lcd(12, 8, 5, 4, 3, 2);

void setup()
{
    Serial.begin(9600); 
    if (!driver.init())
      Serial.println("init failed");
    lcd.begin(16, 2);
    lcd.clear();
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    // Clear the buf array
    memset(buf, 0, sizeof(buf));

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
        int i;
        // Message with a good checksum received, dump it.
        Serial.print("Message: ");
        String msg1 = (char*)buf ;
        Serial.println(msg1);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("XYZ Restraunt");
        lcd.setCursor(0, 1);
        lcd.print(msg1);
    }
}
