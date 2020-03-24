#include <iostream>
#include <vector>
#include "device.h"
#include "motor.h"
#include "nulldevice.h"

int main()
{
   std::vector<device*> polyDevice;
   motor m1("M1");
   motor m2("M2");
   nulldevice n1("n1");
   nulldevice n2("n2");
   nulldevice n3("n3");

   polyDevice.push_back(&m1);
   polyDevice.push_back(&m2);
   polyDevice.push_back(&n1);
   polyDevice.push_back(&n2);
   polyDevice.push_back(&n3);

   for( auto &dev: polyDevice)
   {
      std::cout << "ID_ = " << dev->getID() << "\nCalling reset() results: " << "\n";
      dev->reset();
      std::cout << "\n\n";
   }
   std::cout << "\nAll objects showed and resetted\n";



   return 0;
}
