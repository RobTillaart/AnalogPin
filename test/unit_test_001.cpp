//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-10
// PURPOSE: unit tests for the AnalogPin library
//          https://github.com/RobTillaart/SHT31
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
#include "AnalogPin.h"


unittest_setup()
{
}

unittest_teardown()
{
}


unittest(test_constructor)
{
  AnalogPin AP(0);        // A0 not supported

  assertEqual(7, (int)AP.getPrescaler());
  assertEqual(0, (int)AP.getSmoothWeight());
  assertEqual(0, (int)AP.getNoiseThreshold);
  assertEqual(0, (int)AP.read());
  assertEqual(0, (int)AP.readSmoothed());
  assertEqual(0, (int)AP.readLast());
  assertEqual(0, (int)AP.readPrevious());
}


unittest(test_prescaler)
{
  AnalogPin AP(0); 

  for (int i = 0; i < 8; i++)
  {
    AP.setPrescaler(i);
    assertEqual(i, (int)AP.getPrescaler());
  }
}

unittest(test_noiseThreshold)
{
  AnalogPin AP(0);

  for (int i = 0; i < 31; i += 6)
  {
    AP.setNoiseThreshold(i);
    assertEqual(i, (int)AP.getNoiseThreshold());
  }
}

unittest(test_smooth)
{
  AnalogPin AP(0);

  for (int i = 0; i < 31; i += 6)
  {
    AP.setSmoothWeight(i);
    assertEqual(i, (int)AP.getSmoothWeight());
  }
}

unittest(test_read)
{
  AnalogPin AP(0);

  // TODO unit test cannot read analogPort yet
  // assertEqual(0, (int)AP.read());
  // assertEqual(0, (int)AP.readSmoothed());
  // assertEqual(0, (int)AP.readLast());
  // assertEqual(0, (int)AP.readPrevious());
}


unittest_main()

// --------
