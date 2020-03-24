#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include "device.h"

class motor: public device
{
public:
   motor(const std::string &id): device(id), speed_(0) {}
   virtual ~motor(){}
   virtual void initialise() override { speed_ = 0; std::cout << "initialise motor"; }
   virtual void reset() override { speed_ = 0; std::cout << "reset motor";}
   virtual void shutdown() override { speed_ = 0; std::cout << "shutdown motor";}

   void setSpeed(const double speed) { speed_ = speed; }
   double getSpeed() const { return speed_; }

private:
   double speed_;
};

#endif // MOTOR_H
