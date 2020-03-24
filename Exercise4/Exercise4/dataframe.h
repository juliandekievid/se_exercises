#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <iostream>
#include <array>

class Dataframe
{
public:
   // constructs new dataframe
   Dataframe();
   // initializes dataframe with some input data
   Dataframe(std::array<uint8_t, 255> data);
   // destructs dataframe
   ~Dataframe();

   // shows content of dataframe on standard output
   void show() const;

   // shows all members of dataframe on standard output
   void showAll() const;

   // checks validity of checksum, returns false if not valid
   void checksumIsCorrect();

   // calling member function to return data of the contained dataframe
   std::array<uint8_t, 255> getDataframe();

   // clears dataframe, all 255 datamembers become 0
   void clear();
private:
   // frame with 255 bytes used in communication with roomba robot
   std::array<uint8_t, 255> dataFrame_m;
   uint8_t checksum_m;

   // function which calculates the checksum for the roomba robot
   void setChecksum();

};

#endif // DATAFRAME_H
