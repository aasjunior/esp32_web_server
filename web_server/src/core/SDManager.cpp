#include "SDManager.h"

SDManager::SDManager(int pinCS) : pinCS(pinCS){}

SDStatus SDManager::begin(){
    if(!SD.begin(pinCS)){
        Serial.println("Card Mount Failed");
        return SD_FAILED;
    }

    uint8_t cardType = SD.cardType();
    if(cardType == CARD_NONE){
        Serial.println("No SD card attached");
        return SD_NO_CARD;
    }

    Serial.println("SD Card initialized.");
    return SD_INITIALIZED;
}

void SDManager::listDir(fs::FS &fs, const char * dirname, uint8_t levels){
    Serial.printf("Listing directory: %s\n", dirname);

    File root = fs.open(dirname);
    if(!root){
        Serial.println("Failed to open directory");
        return;
    }
    if(!root.isDirectory()){
        Serial.println("Not a directory");
        return;
    }

    File file = root.openNextFile();
    while(file){
        if(file.isDirectory()){
            Serial.print(" DIR: ");
            Serial.println(file.name());
            if(levels){
                listDir(fs, file.name(), levels - 1);
            }
        }else{
            Serial.print(" FILE: ");
            Serial.print(file.name());
            Serial.print(" SIZE: ");
            Serial.println(file.size());
        }
        file = root.openNextFile();
    }
}