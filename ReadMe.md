# Multi-Zone Environmental Automation System

## Objective

Create a system to automate environment control across multiple zones (e.g., two rooms) using sensors and actuators for each zone.

## Features Covered

* LDR and Thermistor Sensor Readings
* ADC Channel Switching
* Independent Control per Zone
* Mode Switching (Manual/Auto)
* LCD Display
* Layered Architecture (MCAL, HAL, APP)

## Hardware Components

* ATmega32 Microcontroller
* 2x LDR Sensors
* 2x Thermistors
* 2x LEDs (Lighting Control)
* 2x Fans (Temperature Control)
* Push Buttons for Mode Selection
* 16x2 LCD

## Pin Mapping

### LCD Mapping

* RS → PB0
* RW → GND
* E  → PB1
* D4 → PB4
* D5 → PB5
* D6 → PB6
* D7 → PB7

### Button Mapping

* ModeBtn → PD2

### HC05 Mapping

* Bluetooth Tx → MCU Rx  (PD0) as Input
* Bluetooth Rx → MCU Tx  (PD1) as Output

### Zones

#### Zone One

* LDR                              → PA0 (ADC0)  Channel0
* LM35                             → PA1 (ADC1)  Channel1
* DC Motor (Fan)                   → PB3 (OC0)  PWM
* Led (Light)                      → PC0
* Relay (Light)                    → PC1

#### Zone Two

* LDR                              → PA2 (ADC2)  Channel2
* LM35                             → PA3 (ADC3)  Channel3
* DC Motor (Fan)                   → PD5 (OC1A)  PWM
* Led (Light)                      → PC2
* Relay (Light)                    → PC3

#### Zone Three

* LDR                              → PA4 (ADC4)  Channel4
* LM35                             → PA5 (ADC5)  Channel5
* DC Motor (Fan)                   → PD4 (OC1B)  PWM
* Led (Light)                      → PC4
* Relay (Light)                    → PC5

#### Zone Four

* LDR                              → PA6 (ADC6)  Channel6
* LM35                             → PA7 (ADC7)  Channel7
* DC Motor (Fan)                   → PD7 (OC2)   PWM
* Led (Light)                      → PC6
* Relay (Light)                    → PC7

## System Workflow

1. Continuously read sensor data per zone.
2. In Auto Mode:
   * Light turns on if LDR reads low light.
   * Fan turns on if temperature exceeds threshold.
3. In Manual Mode:
   * User manually toggles fan/light with button.
4. LCD alternates between Zone A and Zone B readings.
