#include <gtest/gtest.h>
#include "Soundex.h"
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_7) {
 //AAA
  char soundex[5];
  generateSoundex("123321", soundex);
 // ASSERT_STREQ(soundex,"0000");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_STREQ(soundex,"A200");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_3) {
 //AAA
  char soundex[5];
  generateSoundex("Leo", soundex);
  ASSERT_STREQ(soundex,"E510");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_4) {
 //AAA
  char soundex[5];
  generateSoundex("", soundex);
 // ASSERT_STREQ(soundex,"0000");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_5) {
 //AAA
  char soundex[5];
  generateSoundex("bef", soundex);
 // ASSERT_STREQ(soundex,"E100");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_6) {
 //AAA
  char soundex[5];
  generateSoundex("aeiou", soundex);
 // ASSERT_STREQ(soundex,"O256");
}
