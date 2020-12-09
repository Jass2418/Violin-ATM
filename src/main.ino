//
// Created by Jesus Salazar on 11/24/20.
//

#include "Semaphore.h"
#include "GaugeSensor.h"
#include "Particle.h"
#include "dct.h"

// Sensors Pins
#define STRAIN_GAUGE A2
#define LEFT_MUSCLE A1
#define RIGHT_MUSCLE A0

// Gauge Variables
// Resistor
#define RM 10000

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);

GaugeSensor gaugeSensor(STRAIN_GAUGE,RM);

void setup(){
  const uint8_t val = 0x01;
  dct_write_app_data(&val, DCT_SETUP_DONE_OFFSET, 1);
  Serial.begin(9600);
  Semaphore::begin();
}

void loop(){
  double voltage = gaugeSensor.getVoltage();
  Serial.println(voltage);
  delay(1000);
}