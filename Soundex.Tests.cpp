#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_EQ(soundex,"A200");
  generateSoundex("123", soundex);
  ASSERT_EQ(soundex,"L000");
  generateSoundex("", soundex);
  ASSERT_EQ(soundex,"100");
  generateSoundex("Leo", soundex);
  ASSERT_EQ(soundex,"L000");
 
}
