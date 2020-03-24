#include <iostream>
#include <motor.h>
#include <device.h>

int main()
{
   motor m1("M1");
   motor m2("M2");
   motor m3("M3");

   m1.setSpeed(10);
   m2.setSpeed(20);
   m3.setSpeed(30);

   std::cout << "ID: " << m1.getID() << "\tspeed: " << m1.getSpeed() << "\n";
   std::cout << "ID: " << m2.getID() << "\tspeed: " << m2.getSpeed() << "\n";
   std::cout << "ID: " << m3.getID() << "\tspeed: " << m3.getSpeed() << "\n";

   m1.initialise();
   m2.reset();
   m3.shutdown();
   std::cout << '\n';

   std::cout << "ID: " << m1.getID() << "\tspeed: " << m1.getSpeed() << "\n";
   std::cout << "ID: " << m2.getID() << "\tspeed: " << m2.getSpeed() << "\n";
   std::cout << "ID: " << m3.getID() << "\tspeed: " << m3.getSpeed() << "\n";
   return 0;
}
