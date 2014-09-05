
#include "MCP42XXX.h"
#include "SPI.h"

const int SS_pin = 10;
const int chan_per_device = 2;
MCP42XXX digiPots = MCP42XXX(SS_pin,true,chan_per_device);
const int n_Devices = 2;
const int n_PotValues = 4;
byte potValues[n_PotValues];

void setup() {
  Serial.begin(115200);
  Serial.println(F("MCP2XXX_digitalPotentiometer: starting..."));
}

void loop() {
  for (int i=0; i<64; i+=5) {
    Serial.print(F("Changing Values:"));
    for (int j=0;j<n_PotValues;j++) {
      potValues[j] = (byte)((j*64)+i);
      //potValues[j]=(byte)i;
      Serial.print(" ");  Serial.print(potValues[j]);
    }
    Serial.println();
    digiPots.setValues(potValues,n_PotValues);
    delay(3000);
  }
}
