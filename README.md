MAX31855K_NIST Arduino library

-------------
https://github.com/millerlp/MAX31855K_NIST


This library polls a Maxim Integrated MAX31855K thermocouple-to-digital convertor chip to get
the temperature of a K-type thermocouple. It uses the Maxim-recommended linearization
routine (based on code from 'heypete' https://github.com/heypete/MAX31855-Linearization) on the simultaneously-sampled
internal and external temperatures. This provides a more accurate temperature than
the directly-reported external temperature from the MAX31855K, particularly at the 
extremes of the temperature range (outside the ~ 0C to 50C range).

Based on a fork of the Adafruit_MAX31855K_library for the Adafruit Thermocouple Sensor w/MAX31855K. 

----------------

Create an object from this library by including
```
#include "MAX31855K_NIST.h"
```
in the header of your Arduino program.

Create an object by defining the chip select pin hooked to your MAX31855K
```
#define CS_MAX 8
```
and then 
```
MAX31855K thermocouple(CS_MAX);
```

The function `readCelsius()` can then be used to get the temperature of the 
thermocouple. This function automatically applies the NIST coefficient linearization and returns the adjusted temperature value:
```
double currentTemp = thermocouple.readCelsius();
```

If you want the "raw" temperature value as reported by the MAX31855K, use the
function `readRawCelsius()`:
```
double rawTemp = thermocouple.readRawCelsius();
```




