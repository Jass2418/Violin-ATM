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
// 20g -- 20K ohms
// 50g -- 10K ohms
// 100g -- 6.2K ohms
// 260g -- 3.5K ohms
// 510g -- 2.1K ohms
// 1000g -- 1.2K ohms
// 2000g -- 750 ohms
// 4000g -- 450 ohms
// 7000g -- 310 ohms
// 10000g -- 170 ohms

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

    double getForce(){
      double vO = getVoltage();
      double v = MaxVoltageValue / 1000.0;
      double rF = ((_rm * v) - (_rm * vO)) / vO;
      return 0.0;

    }

  private:
    int _pin;
    int _rm;
};


#endif // VIOLIN_ATM_GAUGESENSOR_H
