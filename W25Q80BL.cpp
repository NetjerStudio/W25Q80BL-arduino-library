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
 */

#include <Arduino.h>
#include <W25Q80BL.h>

W25Q80BL::W25Q80BL(int ChipSelectPin)
{
    _ChipSelectPin = ChipSelectPin;

    pinMode(_ChipSelectPin, OUTPUT);
    digitalWrite(_ChipSelectPin, HIGH);
    SPI.begin();
}

void W25Q80BL::Write(char ADRESS0, char ADRESS1, char ADRESS2, int Data)
{
    digitalWrite(_ChipSelectPin, LOW);
    delay(100);
    SPI.transfer(WriteEnableReg);
    digitalWrite(_ChipSelectPin, HIGH);
    delay(200);
    digitalWrite(_ChipSelectPin, LOW);
    delay(100);
    SPI.transfer(WriteReg);
    SPI.transfer(ADRESS0);
    SPI.transfer(ADRESS1);
    SPI.transfer(ADRESS2);
    SPI.transfer(Data);
    delay(100);
    digitalWrite(_ChipSelectPin, HIGH);
    delay(200);
    digitalWrite(_ChipSelectPin, LOW);
    delay(100);
    SPI.transfer(WriteDisableReg);
    digitalWrite(_ChipSelectPin, HIGH);
}

char W25Q80BL::Read(char ADRESS0, char ADRESS1, char ADRESS2)
{
    digitalWrite(_ChipSelectPin, LOW);
    delay(100);
    SPI.transfer(ReadReg);
    SPI.transfer(ADRESS0);
    SPI.transfer(ADRESS1);
    SPI.transfer(ADRESS2);
    char lec = SPI.transfer(0);
    delay(100);
    digitalWrite(_ChipSelectPin, HIGH);
    return lec;
}

void W25Q80BL::Erase()
{
    digitalWrite(_ChipSelectPin, LOW);
    delay(100);
    SPI.transfer(EraseReg);
    delay(1000);
    digitalWrite(_ChipSelectPin, HIGH);
    delay(100);
    digitalWrite(_ChipSelectPin, LOW);
    delay(100);
    SPI.transfer(EraseVerifReg);
    delay(1000);
    digitalWrite(_ChipSelectPin, HIGH);
}

void W25Q80BL::Standby()
{
    digitalWrite(_ChipSelectPin, LOW);
    delay(100);
    SPI.transfer(PowerDownReg);
    delay(100);
    digitalWrite(_ChipSelectPin, HIGH);
}

void W25Q80BL::WakeUp()
{
    digitalWrite(_ChipSelectPin, LOW);
    delay(100);
    SPI.transfer(WakeUpReg);
    delay(100);
    digitalWrite(_ChipSelectPin, HIGH);
}

void W25Q80BL::EraseBlock(char ADRESS0, char ADRESS1, char ADRESS2)
{
    digitalWrite(_ChipSelectPin, LOW);
    delay(100);
    SPI.transfer(EraseBlockReg);
    delay(200);
    digitalWrite(_ChipSelectPin, HIGH);
}