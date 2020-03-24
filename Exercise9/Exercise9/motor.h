#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include "device.h"

class motor: public device
{
public:
   motor(const std::string &id): device(id), speed_(0) {}
   virtual ~motor();
   virtual void initialise() override { speed_ = 0; std::cout << "\ninitialise motor\n"; }
   virtual void reset() override { speed_ = 0; std::cout << "\nreset motor\n";}
   virtual void shutdown() override { speed_ = 0; std::cout << "\nshutdown motor\n";}

   void setSpeed(const double speed) { speed_ = speed; }
   double getSpeed() const { return speed_; }

private:
   double speed_;
};

#endif // MOTOR_H
