#ifndef ROTATIONMOTOR_H
#define ROTATIONMOTOR_H

#include <iostream>

class RotationMotor {
 public:
   RotationMotor();    // public constructor
   ~RotationMotor();   // public destructor

   void startMotor();
   void shutDown();
   void restart();

   void incRPM(const int speed);
   void decRPM(const int speed);
   int  getRPM() const;
   int  get_rpm_max() const;
   int  get_rpm_min() const;

 private:
   int               rpm      = 0;
   static const int  rpm_max  = 25;
   static const int  rpm_min  = -25;
   bool              start    = false;
};
#endif // ROTATIONMOTOR_H
