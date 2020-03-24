#include <iostream>
#include <array>
#include "dataframe.h"

int main()
{
   // array used to pass in the constructor of class Dataframe
   std::array<uint8_t, 255> DataRobot1 { {19, 5, 29, 2, 25, 13, 0, 182} };

   // making object of class Dataframe with overloaded constructor
   Dataframe Robot1{DataRobot1};

   // calling member function to show content of member variable dataFrame on cout
   Robot1.show();

   // show with use of boolean if checksum resulted zero or not on standard output
   Robot1.checksumIsCorrect();

   // Create new object of class Dataframe getting the data of object Robot1.
   Dataframe Robot2{Robot1.getDataframe()};

   // calling member function to show all content of member variable dataFrame
   Robot2.showAll();

   // clears dataframe, all 255 datamembers become 0
   Robot2.clear();

   // shows dataframe with all zeros
   Robot2.showAll();

   return 0;
}
