#include <iostream>
#include <array>
#include "dataframe.h"

// constructor, initializes all dataframe array elements to zero
Dataframe::Dataframe()
{
   for(auto &element: dataFrame_m)
   {
      element = 0;
   }
   setChecksum();
}

// overloaded constructor, initializes all dataframe array elements to input array
Dataframe::Dataframe(std::array<uint8_t, 255> data)
{
   dataFrame_m = data;
   setChecksum();
}

Dataframe::~Dataframe(){}

// calculates checksum of the content of the dataframe array
void Dataframe::setChecksum()
{
   // loop to number of elements which is specified
   // by element 1 of the array.
   // Add two to it because this element is the second one.
//   for(int i = 1; i <= (dataFrame_m[1] + 2); i++)
//   {
//      checksum_m += dataFrame_m[i];
//   }
//   dataFrame_m[(dataFrame_m[1] + 2)] = checksum_m;

}

// shows content of dataframe array
void Dataframe::show() const
{
   std::cout << "Frame content:\n";
   for(uint8_t i =0; i<static_cast<int>(dataFrame_m[1]+3);i++)
   {
      std::cout << static_cast<int>(dataFrame_m[i]) << ' ';
   }
   std::cout << "\n\n";

//   std::cout << "\nFrame content:\n";
//std::cout << "dataFrame_m[1] = " << ((int)dataFrame_m[1]+3) << "\n";
//   for(auto frameElement: dataFrame_m)
//   {
//      std::cout << (int)frameElement << ' ';
//      if (frameElement  ((int)dataFrame_m[1]+3)) {std::cout << "shit\n"; break; }
//   }
//   std::cout << "\n\n";
}

// shows all members (255) of the contained data frame
void Dataframe::showAll() const
{
      std::cout << "\nFrame content (all members):\n";
      for(auto frameElement: dataFrame_m)
      {
         std::cout << (int)frameElement << ' ';
      }
      std::cout << "\n\n";
}

// checks validity of checksum, show output to standard output
void Dataframe::checksumIsCorrect()
{
   bool checksum_test = false;
   for(uint8_t i = 1; i <= (dataFrame_m[1] + 2); i++)
   {
      checksum_m += dataFrame_m[i];
   }
   if(checksum_m == 0)
   {
      checksum_test = true;
   }
   std::cout << "Memberfunction checksumIsCorrect returned: " << checksum_test << "\n\n";
}

// returns dataframe of contained data
std::array<uint8_t,255> Dataframe::getDataframe()
{
   return dataFrame_m;
}

// clears all content in dataframe, all members become 0
void Dataframe::clear()
{
   std::cout << "Frame content cleared, all members are 0 now.\n\n";
   for(auto &frameElement: dataFrame_m)
   {
    frameElement = 0;
   }
}
















