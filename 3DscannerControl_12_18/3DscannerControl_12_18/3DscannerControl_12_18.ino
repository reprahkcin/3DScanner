#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <multiCameraIrControl.h>

Nikon D3200(6); // Sets camera IR control to pin 6.


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// MOTOR 1 - Focus Motor
int enPin1 = 13;
int stepPin1 = 11;
int dirPin1 = 9;

// MOTOR 2 - Perimeter Drive Motor
int enPin2 = 12;
int stepPin2 = 10;
int dirPin2 = 8;

// ROTARY ENCODER 1 - Left
int incPin1 = 7;
int decPin1 = 6;
int btn1 = 5;

// ROTARY ENCODER 2 - Right
int incPin2 = 4;
int decPin2 = 3;
int btn2 = 2;

// SHOCK SENSOR
int shockPin = 14;

// IR TRIGGER
int irPin = 15;

int dutyDelay = 50;

// STEP QUEUES
int steps1 = 0;
int steps2 = 0;



void setup() {
	Serial.begin(9600);

	// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
		Serial.println(F("SSD1306 allocation failed"));
		for (;;); // Don't proceed, loop forever
	}
	
	display.clearDisplay();
	display.drawPixel(10, 10, WHITE);
		
}

void loop() {
	printSample();
	delay(1000);
}


// USER FUNCTIONS

void pushIn() {
	digitalWrite(dirPin1, HIGH);
	digitalWrite(enPin1, LOW);

	for (int x = steps1; x > 0; x--) 
	{
		digitalWrite(stepPin1, HIGH);
		delay(dutyDelay);
		digitalWrite(stepPin1, LOW);
		delay(dutyDelay);
	}
	
	digitalWrite(enPin1, HIGH);
}

void pullOut() {
	digitalWrite(dirPin1, LOW);
	digitalWrite(enPin1, LOW);

	for (int x = steps1; x > 0; x--)
	{
		digitalWrite(stepPin1, HIGH);
		delay(dutyDelay);
		digitalWrite(stepPin1, LOW);
		delay(dutyDelay);
	}

	digitalWrite(enPin1, HIGH);
}

void trackCW() {
	digitalWrite(dirPin2, HIGH);
	digitalWrite(enPin2, LOW);

	for (int x = steps2; x > 0; x--)
	{
		digitalWrite(stepPin2, HIGH);
		delay(dutyDelay);
		digitalWrite(stepPin2, LOW);
		delay(dutyDelay);
	}

	digitalWrite(enPin2, HIGH);
}

void trackCCW() {
	digitalWrite(dirPin2, LOW);
	digitalWrite(enPin2, LOW);

	for (int x = steps2; x > 0; x--)
	{
		digitalWrite(stepPin2, HIGH);
		delay(dutyDelay);
		digitalWrite(stepPin2, LOW);
		delay(dutyDelay);
	}

	digitalWrite(enPin2, HIGH);
}



void createName() {

}

void shoot() {
	checkSensor();
	D3200.shutterNow();
}

void checkSensor() {
	while (digitalRead(shockPin) > 0) {
		delay(1000);
		checkSensor();
	}
}

void setNear() {

}

void setFar() {

}

void moveToNear() {

}

void start() {

}

void shootStack()

void printSample() {
	int count = 0;

	display.clearDisplay();

	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(10, 5);
	display.println("This is the");
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(10, 20);
	display.println("test text to");
	display.setCursor(10, 35);
	display.println("see what works");
	display.setCursor(10, 50);
	display.print("seconds open: ");
	display.setCursor(24, 50);
	display.println(count);


}