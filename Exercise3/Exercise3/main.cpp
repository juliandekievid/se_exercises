#include <iostream>
#include <array>
#include <iterator>
#include "rotationmotor.h"

void handle_intArrays(std::array<int, 3>& array1, std::array<int, 3>& array2);
void handle_RotationMotors(std::array<RotationMotor, 4>& Motor);

int main()
{
   // C++11 STL array template class, parameters between < and >
   // Using C++11 uniform initialisation by an initializer_list {…}

   std::array<int, 3> array1{2, -2, 3};
   std::array<int, 3> array2;

   std::array<RotationMotor, 4> FourMotors{RotationMotor()};

   // function which handles the stl arrays which contain integers
   handle_intArrays(array1, array2);

   // function which handles the array which contains objects of class RotationMotor
   handle_RotationMotors(FourMotors);
}

void handle_intArrays(std::array<int, 3>& array1, std::array<int, 3>& array2)
{
   // Range-based for loop, el is not the index of a specific
   // element in the array!
   // e1 is a reference to an array element in ar (we used &).
   // auto declaration: type will be deduced by the compiler.
   std::cout << "array1 contains: \n";
   for (auto& el: array1)
   {
      std::cout << el << " ";
      el *= 10;
   }
   std::cout << '\n';

   std::cout << "\nAfter adapting array1 it contains: \n";
   array1[0] = 10 * array1[1];
   for (const auto el: array1)
   {
      std::cout << el << " ";
   }
   std::cout << '\n';

   // copying array1 to array2 using assignment operator
   array2 = array1;
   std::cout << "\nArray1 is copied into array2 which contains: \n";
   for (const auto el: array2)
   {
      std::cout << el << " ";
   }
   std::cout << '\n';
   std::cout << "________________________________________________________________\n";
}

void handle_RotationMotors(std::array<RotationMotor, 4>& Motor)
{
   for (auto& el: Motor)
   {
      el.startMotor();
      el.incRPM(22);
   }
}
/*
1. Output van de bovenstaande coe:

   printing array:
   2 -2 3

   Vermenigvuldigen met 10 en dan element 1 in 0 stoppen. Dan alles met 10 vermenigvuldigen geeft:
   -200 -20 30

2. Als je de '&' weghaalt in de eerste forloop, is de vermenigvuldiging van 10 alleen van kracht op de kopie van het element.
   Buiten de forloop is de originele waarde van het element weer gebruikt.

3. Const in de tweede forloop zorgt ervoor dat er geen element wordt aangepast in de forloop.

4. Omdat in de tweede forloop geen '&' gebruikt, wordt alleen de kopie van de array elementen geprint.

5. De ar() notatie kijkt of element>size, (als positie niet binnen range van het array ligt geeft compiler een error) de ar[] notatie niet doet dit niet.
   Maar de ar[] notatie is sneller in uitvoering.

6. Kopieren van een classic C array kan alleen gedaan worden door te kopieren per array element.
*/
