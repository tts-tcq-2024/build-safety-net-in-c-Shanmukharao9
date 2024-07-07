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
