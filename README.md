# Project overview
This project is an embedded systems prototype for an automatic hydroponic growing system built around an STM32F746NG microcontroller. The system monitors water availability in the nutrient reservoir using an analog water sensor, and automatically controls a water pump through a relay to maintain the required water level for plant growth. It is designed as a practical, low-cost, home-use solution for growing vegetables with minimal manual maintenance.

The repository shows a complete academic project developed in Keil μVision and flashed onto an STM32 board, with supporting firmware, documentation, and hardware interface code. It combines embedded firmware, sensor reading, actuator control, and a graphical display interface.

# What the project aims to achieve
The core aim is to make hydroponic plant care more convenient and reliable by automating the water management process.

In simple terms, the system does the following:

Detects whether water is present or low in the hydroponic setup
Uses an analog sensor to measure water condition
Activates a relay-controlled water pump when water is insufficient
Uses LEDs and a buzzer to signal system status
Displays system state on a GLCD touchscreen interface
Allows the user to start a monitoring cycle via a touchscreen and button input


# Embedded fundamentals demonstrated

Microcontroller-based control

The project is built around the STM32F746NG, which is a Cortex-M7 microcontroller.
It uses the STM32 HAL (Hardware Abstraction Layer) and Keil μVision project configuration.
This demonstrates familiarity with real embedded development tools and hardware platforms.

GPIO configuration

The project configures digital pins for different components such as:
relay control
buzzer
LED
button input
This shows understanding of digital I/O and how peripherals are mapped to microcontroller pins.

Analog signal acquisition

The water sensor is connected to an ADC input and configured in analog mode.
The code initializes ADC1 and reads sensor values in a polling loop.


Actuator control

A relay is used to switch the water pump on and off.
This is a core embedded engineering concept: using a microcontroller to control higher-power devices safely and reliably.

Embedded logic and decision-making

The main loop continuously reads the water sensor and decides:
if water is detected, pump remains off
if water is not detected, pump turns on and alarm indicators trigger


User interface and human interaction

The project includes a GLCD display and touch functionality.
It presents status messages such as:
“Water is detected”
“Water pump is on”
“Water is not detected”


Alarm and diagnostic feedback

LEDs and a buzzer are used to indicate system state.

This is important in embedded design because the system must communicate status to the user even without a PC.

System initialization and hardware bring-up

The firmware configures clocks, PLL, power settings, ADC, GPIO, and display hardware before entering the main control loop.

Modular firmware structure

The code is split into separate modules such as:
main.c
watersensor.c / watersensor.h
relay.c / relay.h
buzzer.c / buzzer.h
led.c / led.h
button.c / button.h
