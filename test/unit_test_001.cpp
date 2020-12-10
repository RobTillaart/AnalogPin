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
  AnalogPin AP(0);        // A0 not supported

}

unittest_teardown()
{
}


unittest(test_constructor)
{
  assertEqual(7, AP.getPrescaler());
  assertEqual(0, AP.getSmoothWeight());
  assertEqual(0, AP.getNoiseThreshold);
  assertEqual(0, AP.read());
  assertEqual(0, AP.readSmoothed());
  assertEqual(0, AP.readLast());
  assertEqual(0, AP.readPrevious());
}


unittest(test_prescaler)
{
  for (int i = 0; i < 8; i++)
  {
    AP.setPrescaler(i);
    assertEqual(i, AP.getPrescaler());
  }
}

unittest(test_noiseThreshold)
{
  for (int i = 0; i < 31; i += 6)
  {
    AP.setNoiseThreshold(i);
    assertEqual(i, AP.getNoiseThreshold());
  }
}

unittest(test_smooth)
{
  for (int i = 0; i < 31; i += 6)
  {
    AP.setSmoothWeight(i);
    assertEqual(i, AP.getSmoothWeight());
  }
}

unittest(test_read)
{
  // TODO unit test cannot read analogPort yet
  // assertEqual(0, AP.read());
  // assertEqual(0, AP.readSmoothed());
  // assertEqual(0, AP.readLast());
  // assertEqual(0, AP.readPrevious());
}


unittest_main()

// --------
