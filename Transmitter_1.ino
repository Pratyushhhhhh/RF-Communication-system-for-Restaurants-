#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

void setup()
{
    Serial.begin(9600); // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    if (Serial.available() > 0) {
        String msg = Serial.readString();
        driver.send((uint8_t *)msg.c_str(), msg.length());
        driver.waitPacketSent();
        
    }
}
