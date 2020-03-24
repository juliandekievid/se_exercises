#ifndef NULLDEVICE_H
#define NULLDEVICE_H

#include <iostream>
#include "device.h"

class nulldevice: public device
{
public:
   nulldevice(const std::string &id): device(id){}
   virtual ~nulldevice(){}

   virtual void initialise() override { std::cout << "initialise nulldevice"; }
   virtual void reset() override { std::cout << "reset nulldevice";}
   virtual void shutdown() override { std::cout << "shutdown nulldevice";}
};

#endif // NULLDEVICE_H
