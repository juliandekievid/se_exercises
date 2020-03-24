#include <iostream>
#include "dofxyrz.h"
#include "rotationmotor.h"
#include "commandprocessor.h"
#include "cartvec2d.h"

void printCoordinates(int no, const DOFxyRz coordinate);

int main()
{
   DOFxyRz coordinate1(3.0, 4.5);
   DOFxyRz coordinate2(2.0, 9.0);
   DOFxyRz coordinate3(1.1, 2.2);

   printCoordinates(1, coordinate1);
   printCoordinates(2, coordinate2);
   printCoordinates(3, coordinate3);
   std::cout << '\n';

   coordinate1.setRz_(2.5);
   coordinate2.setRz_(3.2);
   coordinate3.setRz_(1.6);
   coordinate2 - 50.20;
   coordinate2.vector_2d += coordinate3.vector_2d;

   printCoordinates(1, coordinate1);
   printCoordinates(2, coordinate2);
   printCoordinates(3, coordinate3);

   std::cout << "\nresult heading function: " << coordinate1.heading() << "\n\n";

   printCoordinates(1, coordinate1);
   printCoordinates(2, coordinate2);
   printCoordinates(3, coordinate3);
   std::cout << '\n';

   return 0;
}

void printCoordinates(int no, const DOFxyRz coordinate)
{
   std::cout << "coordinate " << no <<": " << coordinate << '\n';
}
