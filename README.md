## Interfacciamento e gestione del DAC_MCP_4725

### Inclusione librerie

Si include la libreria di gestione della connessione seriale sincrona I2C

    #include <Wire.h>

Si include la libreria di gestione del convertitore Microchip MCP4725 (da installare)

    #include <Adafruit_MCP4725.h>

Si ricorda che Vout = D*Q dove Q = 3.3/4096 essendo il convertitore a 12 bit

### Creazione delle variabili 

Si crea un oggetto di tipo MCP4725

    Adafruit_MCP4725 dac;

Si immagazzinano nella ROM i numeri per generare una sinusoide che oscilli tra 0 Volt e 3.3 Volt partendo d 1.165 V

    const PROGMEM uint16_t DACLookup_FullSine[256] =
    {
      2048, 2098, 2148, 2198, 2248, 2298, 2348, 2398,
      2447, 2496, 2545, 2594, 2642, 2690, 2737, 2784,
      2831, 2877, 2923, 2968, 3013, 3057, 3100, 3143,
      3185, 3226, 3267, 3307, 3346, 3385, 3423, 3459,
      3495, 3530, 3565, 3598, 3630, 3662, 3692, 3722,
      3750, 3777, 3804, 3829, 3853, 3876, 3898, 3919,
      3939, 3958, 3975, 3992, 4007, 4021, 4034, 4045,
      4056, 4065, 4073, 4080, 4085, 4089, 4093, 4094,
      4095, 4094, 4093, 4089, 4085, 4080, 4073, 4065,
      4056, 4045, 4034, 4021, 4007, 3992, 3975, 3958,
      3939, 3919, 3898, 3876, 3853, 3829, 3804, 3777,
      3750, 3722, 3692, 3662, 3630, 3598, 3565, 3530,
      3495, 3459, 3423, 3385, 3346, 3307, 3267, 3226,
      3185, 3143, 3100, 3057, 3013, 2968, 2923, 2877,
      2831, 2784, 2737, 2690, 2642, 2594, 2545, 2496,
      2447, 2398, 2348, 2298, 2248, 2198, 2148, 2098,
      2048, 1997, 1947, 1897, 1847, 1797, 1747, 1697,
      1648, 1599, 1550, 1501, 1453, 1405, 1358, 1311,
      1264, 1218, 1172, 1127, 1082, 1038,  995,  952,
       910,  869,  828,  788,  749,  710,  672,  636,
       600,  565,  530,  497,  465,  433,  403,  373,
       345,  318,  291,  266,  242,  219,  197,  176,
       156,  137,  120,  103,   88,   74,   61,   50,
        39,   30,   22,   15,   10,    6,    2,    1,
         0,    1,    2,    6,   10,   15,   22,   30,
         39,   50,   61,   74,   88,  103,  120,  137,
       156,  176,  197,  219,  242,  266,  291,  318,
       345,  373,  403,  433,  465,  497,  530,  565,
       600,  636,  672,  710,  749,  788,  828,  869,
       910,  952,  995, 1038, 1082, 1127, 1172, 1218,
      1264, 1311, 1358, 1405, 1453, 1501, 1550, 1599,
      1648, 1697, 1747, 1797, 1847, 1897, 1947, 1997
    };

 ### Fase di Setup
 
    Serial.begin(9600);
   
    if(dac.begin(0x60)) Serial.println("DAC ok....");;
    delay(1000);
    Serial.println("Si genera il segnale sinusoidale a partire dai codici binari....");
    delay(1000);

 ### Fase di LOOP

    for (i = 0; i < 256; i++)
      {
        dac.setVoltage(pgm_read_word(&(DACLookup_FullSine_8Bit[i])), false);
      }

dove:

    pgm_read_word(&(DACLookup_FullSine[i]))

serve per leggere i dati dalla ROM e caricarli nel convertitore.

