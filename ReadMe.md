## Multi-Zone Environmental Automation System


### Objective

Create a system to automate environment control across multiple zones (e.g., two rooms) using sensors and actuators for each zone.



### Features Covered

* LDR and Thermistor Sensor Readings
* ADC Channel Switching
* Independent Control per Zone
* Mode Switching (Manual/Auto)
* LCD Display
* Layered Architecture (MCAL, HAL, APP)



### Hardware Components

* ATmega32 Microcontroller
* 2x LDR Sensors
* 2x Thermistors
* 2x LEDs (Lighting Control)
* 2x Fans (Temperature Control)
* Push Buttons for Mode Selection
* 16x2 LCD


### Pin Mapping

* LDR A → ADC0 (PA0)
* LDR B → ADC1 (PA1)
* Thermistor A → ADC2 (PA2)
* Thermistor B → ADC3 (PA3)
* LCD Data → PC0–PC3
* LCD Control: RS → PC4, EN → PC5
* Fan A → PD0
* Fan B → PD1
* Light A → PD2
* Light B → PD3
* Mode Button A → PD4
* Mode Button B → PD5


### System Workflow

1. Continuously read sensor data per zone.
2. In Auto Mode:
   * Light turns on if LDR reads low light.
   * Fan turns on if temperature exceeds threshold.
3. In Manual Mode:
   * User manually toggles fan/light with button.
4. LCD alternates between Zone A and Zone B readings.
