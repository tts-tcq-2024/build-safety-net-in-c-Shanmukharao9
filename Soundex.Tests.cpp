#include <gtest/gtest.h>
#include "Soundex.h"

char soundex[5];

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //Basic tests
    testSoundex("Example", soundex);
    testSoundex("Euler", soundex);
    testSoundex("Gauss", soundex);
    testSoundex("Hilbert", soundex);
    testSoundex("Knuth", soundex);
    testSoundex("Lloyd", soundex);
    testSoundex("Lukasiewicz", soundex);

  //ASSERT_EQ(soundex,"R163");
}

TEST(SoudexTestsuite, SameCodeWithAppropriateDigits) {
 generateSoundex("Ashcroft", soundex);
 generateSoundex("Rupert", soundex);
}
TEST(SoudexTestsuite, VowelsWithAppropriateDigits) { 
 generateSoundex("Ashcraft", soundex);
 generateSoundex("Honeyman", soundex);
 generateSoundex("O'Neil", soundex);
 generateSoundex("Van Dyke", soundex);
 generateSoundex("A", soundex);
 generateSoundex("", soundex);
 generateSoundex("123", soundex);
 generateSoundex("H3ll0W0rld", soundex);
 generateSoundex("AA", soundex);
 generateSoundex("R123", soundex);
 generateSoundex("Clark", soundex);
 generateSoundex("B", soundex);
 generateSoundex("Z", soundex);
 generateSoundex("C", soundex);
 generateSoundex("BF", soundex);
 generateSoundex("Honeymanbagsss", soundex);
 generateSoundex("McDonald", soundex);
 generateSoundex("John's", soundex);
 generateSoundex("Smith-Jones", soundex);
 generateSoundex("RoBeRt", soundex);
 generateSoundex("Bbbb", soundex);
 generateSoundex("//;\n1;2", soundex);
 generateSoundex("Andwtrs", soundex);
 generateSoundex("OCjjnrr", soundex);
 generateSoundex("123123", soundex);
}
 
