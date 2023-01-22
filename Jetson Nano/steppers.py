# Import the required libraries
from gpiozero import LED, Button
from time import sleep

# Define the GPIO pins for the stepper motor A
enable_pin_A = LED(5)
direction_pin_A = LED(6)
step_pin_A = LED(13)

# Define the GPIO pins for the stepper motor B
enable_pin_B = LED(17)
direction_pin_B = LED(27)
step_pin_B = LED(22)

# Enable the stepper motors
enable_pin_A.on()
enable_pin_B.on()

# Function to move stepper A in one direction
def move_stepper_A_forward():
    direction_pin_A.on()
    step_pin_A.on()
    sleep(0.01)
    step_pin_A.off()

# Function to move stepper A in the opposite direction
def move_stepper_A_backward():
    direction_pin_A.off()
    step_pin_A.on()
    sleep(0.01)
    step_pin_A.off()

# Function to move stepper B in one direction
def move_stepper_B_forward():
    direction_pin_B.on()
    step_pin_B.on()
    sleep(0.01)
    step_pin_B.off()

# Function to move stepper B in the opposite direction
def move_stepper_B_backward():
    direction_pin_B.off()
    step_pin_B.on()
    sleep(0.01)
    step_pin_B.off()

# Main loop
while True:
    # Check for keyboard input
    key = input("Press arrow keys to move stepper motors (or 'q' to quit): ")

    # Check the input and call the appropriate function
    if key == 'up':
        move_stepper_A_forward()
    elif key == 'down':
        move_stepper_A_backward()
    elif key == 'right':
        move_stepper_B_forward()
    elif key == 'left':
        move_stepper_B_backward()
    elif key == 'q':
        break
    else:
        print("Invalid input")

# Disable the stepper motors
enable_pin_A.off()
enable_pin_B.off()
