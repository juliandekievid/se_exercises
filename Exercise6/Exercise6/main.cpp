#include <iostream>
#include <cartvec2d.h>

int main()
{
   CartVec2D vec1(3, 4);
   CartVec2D vec2(5, 6);
   CartVec2D vec3(2, 2);

   std::cout << "vec1 = " << vec1 << "\n" << "vec2 = " << vec2 << '\n' << "vec3 = " << vec3 << "\n\n";
   std::cout << "vec1: " << vec1  << "\n\n";
   std::cout << "-vec1: " << -vec1  << "\n\n";
   std::cout << "(vec1 *= vec2): " << (vec1 *= vec2)  << "\n\n";
   std::cout << "vec1: " << vec1  << "\n\n";
   std::cout << "vec1: " << vec1  << "\n\n";
   std::cout << "vec3 = (vec1 * 2.0): " << (vec3 * 2.0) << "\n\n";
   std::cout << "vec3 = (vec1 * 2.0): " << (5.0 * vec2) << "\n\n";


   return 0;
}


