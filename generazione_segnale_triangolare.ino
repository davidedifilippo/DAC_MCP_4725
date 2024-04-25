/**************************************************************************/
/*! 
    @file     trianglewave.pde
    @author   Adafruit Industries
    @license  BSD (see license.txt)

    This example will generate a triangle wave with the MCP4725 DAC.   

    This is an example sketch for the Adafruit MCP4725 breakout board
    ----> http://www.adafruit.com/products/935
 
    Adafruit invests time and resources providing this open source code, 
    please support Adafruit and open-source hardware by purchasing 
    products from Adafruit!
*/
/**************************************************************************/
#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

void setup(void) {
  Serial.begin(9600);


  // For Adafruit MCP4725A1 the address is 0x62 (default) or 0x63 (ADDR pin tied to VCC)
  // For MCP4725A0 the address is 0x60 or 0x61
  // For MCP4725A2 the address is 0x64 or 0x65
  if(dac.begin(0x60))   Serial.println("Convertitore DAC OK .......");;
    
  Serial.println("Generating a triangle wave");
}

void loop(void) {
    uint32_t counter;
    // Salgo linearmente da 0 a 4096
    for (counter = 0; counter < 4095; counter++)
    {
      dac.setVoltage(counter, false);
    }

  // Scendo linearmente da 4096 a 0
    for (counter = 4095; counter > 0; counter--)
    {
      dac.setVoltage(counter, false);
    }
}
