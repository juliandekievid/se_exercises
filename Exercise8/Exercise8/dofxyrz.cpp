#include <iostream>
#include <iomanip>
#include <cmath>
#include "dofxyrz.h"
#include "cartvec2d.h"

std::ostream& operator<<(std::ostream &os, const DOFxyRz &coordinate)
{
   std::cout.precision(2);
   return os << coordinate.vector_2d << "[" << std::fixed << coordinate.Rz_ << " rad]";
}

DOFxyRz::DOFxyRz()
{
   vector_2d.set_x(0);
   vector_2d.set_y(0);
}

DOFxyRz::DOFxyRz(double x, double y)
{
   vector_2d.set_x(x);
   vector_2d.set_y(y);
}

void showVector(const CartVec2D vector)
{
   std::cout << vector;
}

CartVec2D DOFxyRz::heading() const
{
   CartVec2D result;
   result.set_x(cos(Rz_));
   result.set_y(sin(Rz_));
   return result;
}

DOFxyRz &DOFxyRz::operator+=(const CartVec2D &rhs)
{
   vector_2d += rhs;
   return *this;
}

DOFxyRz &DOFxyRz::operator+=(const double &rhs)
{
   double z{0};
   z+=rhs;
   while(z > PI_ || z < -PI_)
   {
      if(z > PI_)
      {
         z-=PI_;
      }
      else if(z < PI_)
      {
         z+=PI_;
      }
   }
   Rz_ += z;
   return *this;
}

DOFxyRz &DOFxyRz::operator+(const CartVec2D &rhs)
{
   DOFxyRz result;
   result.vector_2d + rhs;
   return *this;
}

DOFxyRz &DOFxyRz::operator+(const double &rhs)
{
   double z{0};
   z+=rhs;
   while(z > PI_ || z < -PI_)
   {
      if(z > PI_)
      {
         z-=PI_;
      }
      else if(z < PI_)
      {
         z+=PI_;
      }
   }
   Rz_ += z;
   return *this;
}

DOFxyRz &DOFxyRz::operator-(const double &rhs)
{
   double z{0};
   z+=rhs;
   while(z > PI_ || z < -PI_)
   {
      if(z > PI_)
      {
         z-=PI_;
      }
      else if(z < PI_)
      {
         z+=PI_;
      }
   }
   Rz_ -= z;
   return *this;
}

DOFxyRz &DOFxyRz::operator-=(const CartVec2D &rhs)
{
   DOFxyRz result;
   result.vector_2d -= rhs;
   return *this;
}

DOFxyRz &DOFxyRz::operator-(const CartVec2D &rhs)
{
   DOFxyRz result;
   result.vector_2d - rhs;
   return *this;
}
