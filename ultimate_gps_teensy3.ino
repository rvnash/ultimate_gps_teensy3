// GPSExample.cpp - How to use the GPS code for Adafruit Ultimate GPS

/*
 * Copyright (C) 2014 by Richard Nash (KC3ARY)
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <WProgram.h>
#include "GPS.h"

HardwareSerial &gpsSerial = Serial1;
GPS gps(&gpsSerial,true);

// setup() method runs once, when the sketch starts
void setup()
{
  Serial.begin(38400); // For debugging output over the USB port
  gps.startSerial(9600);
  delay(1000);
  gps.setSentencesToReceive(OUTPUT_RMC_GGA);
}

// the loop() methor runs over and over again,
// as long as the board has power
void loop()
{
  if (gps.sentenceAvailable()) gps.parseSentence();

  if (gps.newValuesSinceDataRead()) {
    gps.dataRead();
    Serial.printf("Location: %f, %f altitude %f\n\r",
		  gps.latitude, gps.longitude, gps.altitude);
  }
}
