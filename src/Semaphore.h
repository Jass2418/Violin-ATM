//
// Created by Jesus Salazar on 12/9/20.
//

#ifndef VIOLIN_ATM_SEMAPHORE_H
#define VIOLIN_ATM_SEMAPHORE_H

#include "Particle.h"


class Semaphore{
  public:
    static void begin(){
      RGB.control(true);
      RGB.brightness(64);
      RGB.color(255, 0, 0);  /// Red
      delay(1000);
      RGB.color(0, 0, 0);  /// Black
      delay(100);
      RGB.color(255, 0, 0);  /// Red
      delay(1000);
      RGB.color(0, 0, 0);  /// Black
      delay(100);
      RGB.color(255, 255, 0);  /// Yellow
      delay(1000);
      RGB.color(0, 0, 0);  /// Black
      delay(100);
      RGB.color(255, 255, 0);  /// Yellow
      delay(1000);
      RGB.color(0, 0, 0);  /// Black
      delay(100);
      RGB.color(0, 255, 0);  /// Green
    }
};


#endif // VIOLIN_ATM_SEMAPHORE_H
