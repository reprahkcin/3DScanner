#include <splash.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <multiCameraIrControl.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET     4 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Nikon D3200(15);

// MOTOR 1 - Focus Motor
int enPin1 = 13;
int stepPin1 = 11;
int dirPin1 = 9;

// MOTOR 2 - Perimeter Drive Motor
int enPin2 = 12;
int stepPin2 = 10;
int dirPin2 = 8;

// MISC MOTOR VARIABLES
int dutyDelay = 50;

// ROTARY ENCODER 1 - Left
int aState1;
int aLastState1;
int counter1;
int incPin1 = 7;
int decPin1 = 6;
int btn1 = 5;

// ROTARY ENCODER 2 - Right
int aState2;
int aLastState2;
int counter2;
int incPin2 = 4;
int decPin2 = 3;
int btn2 = 2;

// SHOCK SENSOR
int shockPin = 14;

// IR TRIGGER
int irPin = 15;

// STEP QUEUES
int steps1 = 0;
int steps2 = 0;

// STATE BOOLS
bool isListening = false;

// CONFIGURATION VARIABLES
int numShots;
int numStacks;



void setup() {
	
	Serial.begin(9600);
	initPins();
	
	aLastState1 = digitalRead(incPin1);
	aLastState2 = digitalRead(incPin2);

	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
		Serial.println(F("SSD1306 allocation failed"));
		for (;;);
		display.display();

		delay(2000);

		display.clearDisplay();

		display.drawPixel(10, 10, WHITE);
		display.display();
		delay(2000);

	}
}

void loop() {
	Serial.print(counter1);
//	listen();
//	display.clearDisplay();
//	display.setTextSize(1);
//	display.setTextColor(WHITE);
//	display.setCursor(10, 35);
//	display.println(counter1);
//	display.display();
}


// USER FUNCTIONS

void initPins() 
{
	pinMode(enPin1, OUTPUT);
	pinMode(stepPin1, OUTPUT);
	pinMode(dirPin1, OUTPUT);

	pinMode(enPin2, OUTPUT);
	pinMode(stepPin2, OUTPUT);
	pinMode(dirPin2, OUTPUT);

	pinMode(incPin1, INPUT);
	pinMode(decPin1, INPUT);
	pinMode(incPin2, INPUT);
	pinMode(decPin2, INPUT);

	pinMode(btn1, INPUT);
	pinMode(btn2, INPUT);

	pinMode(shockPin, INPUT);
	
	pinMode(irPin, OUTPUT);
}

void listen() {
	aState1 = digitalRead(incPin1);
	if (aState1 != aLastState1) {
		if (digitalRead(decPin1) != aState1) {
			counter1++;
		}else 
		{
			counter1--;
		}
	}
	aState2 = digitalRead(incPin2);
	if (aState2 != aLastState2) {
		if (digitalRead(decPin1) != aState2) {
			counter2++;
		}
		else
		{
			counter2--;
		}
	}
}

void pushIn(int stepsToTake) 
{
	digitalWrite(dirPin1, HIGH);
	digitalWrite(enPin1, LOW);

	for (int x = stepsToTake; x > 0; x--) 
	{
		digitalWrite(stepPin1, HIGH);
		delay(dutyDelay);
		digitalWrite(stepPin1, LOW);
		delay(dutyDelay);
	}
	digitalWrite(enPin1, HIGH);
}

void pullOut(int stepsToTake) 
{
	digitalWrite(dirPin1, LOW);
	digitalWrite(enPin1, LOW);

	for (int x = stepsToTake; x > 0; x--)
	{
		digitalWrite(stepPin1, HIGH);
		delay(dutyDelay);
		digitalWrite(stepPin1, LOW);
		delay(dutyDelay);
	}

	digitalWrite(enPin1, HIGH);
}

void trackCW(int stepsToTake) 
{
	digitalWrite(dirPin2, HIGH);
	digitalWrite(enPin2, LOW);

	for (int x = stepsToTake; x > 0; x--)
	{
		digitalWrite(stepPin2, HIGH);
		delay(dutyDelay);
		digitalWrite(stepPin2, LOW);
		delay(dutyDelay);
	}

	digitalWrite(enPin2, HIGH);
}

void trackCCW(int stepsToTake) 
{
	digitalWrite(dirPin2, LOW);
	digitalWrite(enPin2, LOW);

	for (int x = stepsToTake; x > 0; x--)
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

int count = 0;
void printSample() {
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
	display.println(count);
	count++;
	display.display();
	delay(1000);
}