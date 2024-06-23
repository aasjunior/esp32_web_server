#ifndef SD_MANAGER_H
#define SD_MANAGER_H

#include <SD.h>
#include "Enums.h"

class SDManager{
public:
    SDManager(int pinCS);
    SDStatus begin();
    void listDir(fs::FS &fs, const char * dirname, uint8_t levels);

private:
    int pinCS;
};

#endif