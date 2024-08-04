#include <gtest/gtest.h>
#include "Soundex.h"

char soundex[5];

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //Basic tests
    generateSoundex("Example", soundex);
    generateSoundex("Euler", soundex);
    generateSoundex("Gauss", soundex);
    generateSoundex("Hilbert", soundex);
    generateSoundex("Knuth", soundex);
    generateSoundex("Lloyd", soundex);
    generateSoundex("Lukasiewicz", soundex);
      // Edge cases
    generateSoundex("", soundex);       
    generateSoundex("A", soundex);      
    generateSoundex("Bb", soundex);     
    generateSoundex("Pfister", soundex);
    generateSoundex("Jackson", soundex);
    // Case insensitivity
    generateSoundex("example", soundex);
   generateSoundex("euler", soundex);
   generateSoundex("GAUSS", soundex);
   generateSoundex("hilBert", soundex);
   generateSoundex("kNutH", soundex);

}


 
