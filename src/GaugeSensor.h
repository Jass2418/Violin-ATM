//
// Created by Jesus Salazar on 12/9/20.
//

#ifndef VIOLIN_ATM_GAUGESENSOR_H
#define VIOLIN_ATM_GAUGESENSOR_H

#define MaxRawValue 4095
#define MinRawValue 0
#define MaxVoltageValue 3300 // mV
#define MinVoltageValue 0 // mV

#include "Particle.h"

struct GaugeSpec{
  int resistence;
  int grams;
};

enum Unit{
  Grams,
  Kg,
  Newtons
};

class GaugeSensor{
  public:
    GaugeSensor(int pin, int rm){
      _pin = pin;
      _rm = rm;
    }

    int getRawValue(){
      return analogRead(_pin);
    }

    double getVoltage(){
      int rawValue = getRawValue();
      return map(rawValue,MinRawValue,MaxRawValue,
                 MinVoltageValue,MaxVoltageValue) / 1000.0;
    }

    double getForce(int unit){
      double vO = getVoltage();
      double v = MaxVoltageValue / 1000.0;
      int rF = (vO * _rm) / (v -vO);
      int length = sizeof(gaugeSpecs)/sizeof(gaugeSpecs[0]);
      for (int i = 0; i < length - 1 ; i++) {
        int lowerRange = gaugeSpecs[i].resistence;
        int upperRange = gaugeSpecs[i+1].resistence;
        if(isInRange(lowerRange,upperRange,rF)){
          double force = map(rF,lowerRange,upperRange,
                     gaugeSpecs[i].grams,gaugeSpecs[i+1].grams) / 1.0;
          switch (unit)
          {
            case Unit::Grams:
              return force;
            case Unit::Kg:
              return force / 1000.0;
            case Unit::Newtons:
              return (force / 1000.0) * 9.80665;
            default:
              return force;
          }
        }
      }
      return 0.0;
    }

  private:
    int _pin;
    int _rm;
    GaugeSpec gaugeSpecs[12] = {
        {0,11000},
        {170,10000},
        {310,7000},
        {450,4000},
        {750,2000},
        {1200,1000},
        {2100,510},
        {3500,260},
        {6200,100},
        {10000,50},
        {20000,20},
        {50000,0},
    };

  bool isInRange(int low, int high, int x)
  {
    return  ((x-low) <= (high-low));
  }

};

#endif // VIOLIN_ATM_GAUGESENSOR_H
