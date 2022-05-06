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

#ifndef W25Q80BL_h
#define W25Q80BL_h

#include <Arduino.h>
#include <SPI.h>

#define     WriteEnableReg      0x06
#define     WriteDisableReg     0x04
#define     WriteReg            0x02
#define     ReadReg             0x03
#define     EraseReg            0xC7
#define     EraseVerifReg       0x60
#define     PowerDownReg        0xB9
#define     WakeUpReg           0xAB
#define     EraseBlockReg       0x20

class W25Q80BL
{
    public:
        W25Q80BL(int ChipSelectPin);

        void Write(char ADRESS0, char ADRESS1, char ADRESS2, int Data);
        char Read(char ADRESS0, char ADRESS1, char ADRESS2);
        void Erase();
        void Standby();
        void WakeUp();
        void EraseBlock(char ADRESS0, char ADRESS1, char ADRESS2);

    private:
        int _ChipSelectPin;

};

#endif