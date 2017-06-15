/*************************************************** 
  This is a library for the Adafruit Thermocouple Sensor w/MAX31855K

  Designed specifically to work with the Adafruit Thermocouple Sensor
  ----> https://www.adafruit.com/products/269

  These displays use SPI to communicate, 3 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
  
  Modified June 2017 by Luke Miller, adding in code from 
  https://github.com/heypete/MAX31855-Linearization 'heypete'
  to correct Celsius temperature values. This version also uses the
  simultaneously-read internal and external temperatures from a single
  poll of the MAX31855 to then apply the NIST linearization.
  
 ****************************************************/

#ifndef MAX31855K_NIST_H
#define MAX31855K_NIST_H

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class MAX31855K {
 public:
  MAX31855K(int8_t SCLK, int8_t CS, int8_t MISO);
  MAX31855K(int8_t CS);

  double readInternal(void);
  double readCelsius(void);  // NIST-corrected version
  double readRawCelsius(void); // MAX31855 default version
  double readFarenheit(void);
  uint8_t readError();

 private:
  int8_t sclk, miso, cs, hSPI;
  uint32_t spiread32(void);
  uint32_t hspiread32(void);
};

#endif
