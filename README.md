MAX31855K_NIST

-------------

This library polls a Maxim Integrated MAX31855K thermocouple-to-digital convertor chip to get
the temperature of a K-type thermocouple. It uses the Maxim-recommended linearization
routine (based on code from 'heypete' https://github.com/heypete/MAX31855-Linearization) on the simultaneously-sampled
internal and external temperatures. This provides a more accurate temperature than
the directly-reported external temperature from the MAX31855K, particularly at the 
extremes of the temperature range (outside the ~ 0C to 50C range).

Based on a fork of the Adafruit_MAX31855K_library for the Adafruit Thermocouple Sensor w/MAX31855K. 