#ifndef SOUNDEX_H
#define SOUNDEX_H
#include "Soundex.h"
#include <ctype.h>
#include <string.h>
#include "Soundex.h"
#include <cctype>

char getSoundexCode(char c)
{
    static const char soundexCodes[26] = {'0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'};
    return soundexCode[toupper(c) - 'A'];
}

char elmZroRptVlu (char prevcode, std::string& soundex, size i, const std::string& name)
{
   char code = getSoundexCode(name[i]);
   if (code != '0' && code != prevcode)
    {
        soundex += code;
        prevcode = code;
    } 
    return prevcode;
}

char getStringCode(const std::string& name, std::string& soundex, char prevcode)
{
    for (size i = 1; i < name.length() && soundex.length() < 4; ++i)
    {
        char prevCode = elmZroRptVlu(prevCode, soundex, i, name);
    }
    return prevCode;
}

std::string generateSoundex(const std::string& name) 
{
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    prevCode = getStringCode(name, soundex, prevCode);
    
    while (soundex.length() < 4) 
    {
        soundex += '0';
    }

    return soundex;
}
