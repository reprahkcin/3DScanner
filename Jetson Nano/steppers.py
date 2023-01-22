import RPi.GPIO as GPIO
import keyboard

# Stepper A
StepperA_EnablePin = 5
StepperA_DirPin = 6
StepperA_StepPin = 13

# Stepper B
StepperB_EnablePin = 17
StepperB_DirPin = 27
StepperB_StepPin = 22

GPIO.setmode(GPIO.BCM)
GPIO.setup(StepperA_EnablePin, GPIO.OUT)
GPIO.setup(StepperA_DirPin, GPIO.OUT)
GPIO.setup(StepperA_StepPin, GPIO.OUT)
GPIO.setup(StepperB_EnablePin, GPIO.OUT)
GPIO.setup(StepperB_DirPin, GPIO.OUT)
GPIO.setup(StepperB_StepPin, GPIO.OUT)

GPIO.output(StepperA_EnablePin, GPIO.HIGH)
GPIO.output(StepperB_EnablePin, GPIO.HIGH)

def move_stepperA(direction):
    if direction == "up":
        # Set the direction of the motor
        GPIO.output(StepperA_DirPin, GPIO.HIGH)
        GPIO.output(StepperA_StepPin, GPIO.HIGH)
        GPIO.output(StepperA_StepPin, GPIO.LOW)
        elif direction == "down":
        # Set the opposite direction of the motor
        GPIO.output(StepperA_DirPin, GPIO.LOW)
        GPIO.output(StepperA_StepPin, GPIO.HIGH)
        GPIO.output(StepperA_StepPin, GPIO.LOW)

def move_stepperB(direction):
    if direction == "right":
        # Set the direction of the motor
        GPIO.output(StepperB_DirPin, GPIO.HIGH)
        GPIO.output(StepperB_StepPin, GPIO.HIGH)
        GPIO.output(StepperB_StepPin, GPIO.LOW)
    elif direction == "left":
        # Set the opposite direction of the motor
        GPIO.output(StepperB_DirPin, GPIO.LOW)
        GPIO.output(StepperB_StepPin, GPIO.HIGH)
        GPIO.output(StepperB_StepPin, GPIO.LOW)

while True:
    if keyboard.is_pressed("up"):
        move_stepperA("up")
    elif keyboard.is_pressed("down"):
        move_stepperA("down")
    elif keyboard.is_pressed("right"):
        move_stepperB("right")
    elif keyboard.is_pressed("left"):
        move_stepperB("left")
    elif keyboard.is_pressed("esc"):
        break

GPIO.cleanup()

