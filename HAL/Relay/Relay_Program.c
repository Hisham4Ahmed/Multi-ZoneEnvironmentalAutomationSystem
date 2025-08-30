/**
 * @file     Relay_Program.c
 * @author   Developer  Mohammed Atif      (Email: medoatifatif@gmail.com)
 * @author   Reviewer   Naira Mohammed
 * @brief    Relay control program for initializing and switching relay states.
 * @version  0.1
 * @date     2025-08-24
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "../../Common/Config.h"
#if Relay_Driver

#include "Relay_Interface.h"

/** Relay pin mapping for each zone. */
static uint8_t Relays_Zone[MaxZones] = Zones_Relay_Pin;

void hRelay_Init(uint8_t ZoneNumber) {
    if (ZoneNumber >= 1 && ZoneNumber <= MaxZones) {
        DIO_Direction_Pin(Relays_Group, Relays_Zone[ZoneNumber - 1], DIO_Output);
    }
    else {
        // Ignore Invalid Zone Number 
    }
}

void hRelay_On(uint8_t ZoneNumber) {
    if (ZoneNumber >= 1 && ZoneNumber <= MaxZones) {
        DIO_Write_Pin(Relays_Group, Relays_Zone[ZoneNumber - 1], DIO_High);
    }
    else {
        // Ignore Invalid Zone Number 
    }
}

void hRelay_Off(uint8_t ZoneNumber) {
    if (ZoneNumber >= 1 && ZoneNumber <= MaxZones) {
        DIO_Write_Pin(Relays_Group, Relays_Zone[ZoneNumber - 1], DIO_Low);
    }
    else {
        // Ignore Invalid Zone Number 
    }
}

void hRelay_Toggle(uint8_t ZoneNumber) {
    if (ZoneNumber >= 1 && ZoneNumber <= MaxZones) {
        if (DIO_Read_Pin(Relays_Group, Relays_Zone[ZoneNumber - 1]) == DIO_High) {
            DIO_Write_Pin(Relays_Group, Relays_Zone[ZoneNumber - 1], DIO_Low);
        }
        else if (DIO_Read_Pin(Relays_Group, Relays_Zone[ZoneNumber - 1]) == DIO_Low) {
            DIO_Write_Pin(Relays_Group, Relays_Zone[ZoneNumber - 1], DIO_High);
        }
    }
    else {
        // Ignore Invalid Zone Number 
    }
}


#endif /*Relay_Driver*/