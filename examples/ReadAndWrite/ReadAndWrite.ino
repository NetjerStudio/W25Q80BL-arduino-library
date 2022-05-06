/*
 *    _   _      _   _             _____ _             _ _       
 *   | \ | |    | | (_)           /  ___| |           | (_)      
 *   |  \| | ___| |_ _  ___ _ __  \ `--.| |_ _   _  __| |_  ___  
 *   | . ` |/ _ \ __| |/ _ \ '__|  `--. \ __| | | |/ _` | |/ _ \ 
 *   | |\  |  __/ |_| |  __/ |    /\__/ / |_| |_| | (_| | | (_) |
 *   \_| \_/\___|\__| |\___|_|    \____/ \__|\__,_|\__,_|_|\___/ 
 *                 _/ |                                          
 *                |__/                                           
 *    _____ _                  ___  ___                  _       
 *   /  ___| |                 |  \/  |                 (_)      
 *   \ `--.| |_ _____   _____  | .  . | ___  _   _  __ _ _ _ __  
 *    `--. \ __/ _ \ \ / / _ \ | |\/| |/ _ \| | | |/ _` | | '_ \ 
 *   /\__/ / ||  __/\ V /  __/ | |  | | (_) | |_| | (_| | | | | |
 *   \____/ \__\___| \_/ \___| \_|  |_/\___/ \__,_|\__, |_|_| |_|
 *                                                  __/ |        
 *                                                 |___/         
 * 
 *  Créé le 3 Mai 2022
 *  Librairie W25Q80BL V1.0
 *  ATTENTION ! Eviter d'écrire sur les 3 premiers bloques !
 *  ATTENTION ! Tension supporté : 3.3V !
 * 
 *  Arduino Uno : 
 * #CS (1) sur Pin 8
 * DO (2) sur 12 (MISO)
 * #WP (3) sur 3.3V
 * GND (4) sur GND
 * DI (5) sur 11 (MOSI)
 * CLK (6) sur 13 (SCLK)
 * #HOLD (7) sur sur 3.3V
 * VCC (8) sur 3.3V
 */

#include <W25Q80BL.h>

#define CS 8

W25Q80BL Memory (CS);

char MemoryRead;

void setup () {
    Serial.begin(9600);
    Memory.Erase();
    Serial.println("Write '0x20' on the Block '0x000015'...");
    Memory.Write(0x00,0x00,0x15,0x20);
    Serial.println("Read the Block '0x000015'...");
    MemoryRead = Memory.Read(0x00,0x00,0x15);
    Serial.print(MemoryRead, BIN);
    Serial.print(" | ");
    Serial.print(MemoryRead, HEX);
    Serial.print(" | ");
    Serial.println(MemoryRead, DEC);
}

void loop() 
{
}