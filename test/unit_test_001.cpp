//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2023-05-02
// PURPOSE: unit tests for the LUHN checksum
//          https://github.com/RobTillaart/LUHN
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)


#include <ArduinoUnitTests.h>

#include "Arduino.h"
#include "LUHN.h"


unittest_setup()
{
    fprintf(stderr, "LUHN_LIB_VERSION: %s\n", (char *) LUHN_LIB_VERSION);
}

unittest_teardown()
{
}


unittest(test_constructor)
{
  LUHN luhn;

  assertEqual('0', luhn.reset());
  assertEqual('0', luhn.reset());
}


unittest(test_isValid)
{
  LUHN luhn;

  assertTrue(luhn.isValid("0"));
  assertTrue(luhn.isValid("79927398713"));
  assertTrue(luhn.isValid("11111111111111111111"));
}


unittest(test_generateChecksum)
{
  LUHN luhn;

  assertEqual('3', luhn.generateChecksum("7992739871"));
}


unittest(test_generate)
{
  LUHN luhn;

  for (int i = 0; i < 10; i++)
  {
    char buffer[24];
    char prefix[10] = "007";
    assertTrue(luhn.generate(buffer, 20, prefix));
    assertTrue(luhn.isValid(buffer));
    fprintf(stderr, "%d %s\n", i, buffer);
  }
}


unittest(test_stream)
{
  LUHN luhn;

  luhn.reset();
  char buffer[24] = "7992739871";
  for (int i = 0; i < strlen(buffer); i++)
  {
    char c = luhn.add(buffer[i]);
    fprintf(stderr, "%d %c\n", i, c);
  }
  assertEqual('3', luhn.reset());
}




unittest_main()


//  -- END OF FILE --
