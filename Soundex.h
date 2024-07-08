#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>


char getSoundexCode(char c) {
    static const char *codes = "01230120022455012623010202";
    return isalpha(c) ? codes[toupper(c) - 'A'] : '0';
}

void initialSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);
    soundex[1] = '\0';
}

void appendSoundexCode(char *soundex, int *index, char code) {
    if (*index < 4) {
        soundex[*index] = code;
        (*index)++;
        soundex[*index] = '\0';
    }
}

void fillSoundex(char *soundex, int index) {
    while (index < 4) {
        soundex[index++] = '0';
    }
    soundex[4] = '\0';
}

void processCharacter(char *soundex, int *index, char code, char *prevCode) {
    if (code != '0' && code != *prevCode) {
        appendSoundexCode(soundex, index, code);
        *prevCode = code;
    }
}

void iterateName(const char *name, char *soundex, int *index) {
    char prevCode = getSoundexCode(name[0]);
    for (int i = 1; name[i] != '\0' && *index < 4; i++) {
        char code = getSoundexCode(name[i]);
        processCharacter(soundex, index, code, &prevCode);
    }
}

void generateSoundex(const char *name, char *soundex) {
    if (!name || name[0] == '\0') {
        soundex[0] = '\0';
        return;
    }

    initialSoundex(name, soundex);
    int index = 1;
    iterateName(name, soundex, &index);
    fillSoundex(soundex, index);
}

#endif // SOUNDEX_H
