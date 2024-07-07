#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}
void generateSoundex(const char *name, char *soundex) {
    if (name == nullptr || soundex == nullptr || name[0] == '\0') {
        soundex[0] = '\0';
        return;
    }

    soundex[0] = std::toupper(static_cast<unsigned char>(name[0]));
    int sIndex = 1;
    char prevCode = getSoundexCode(name[0]);

    for (int i = 1; name[i] != '\0' && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            
            if (!(i > 1 && (name[i - 1] == 'h' || name[i - 1] == 'w') && name[i - 2] == 'a')) {
                soundex[sIndex++] = code;
            }
        }
        prevCode = code;
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}
