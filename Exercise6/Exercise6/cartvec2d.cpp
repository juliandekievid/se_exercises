#include <iostream>
#include "cartvec2d.h"

/// overloading of << output operator
std::ostream& operator<<(std::ostream &os, const CartVec2D &rhs)
{
   return os << "[" << rhs.getX() << ", " << rhs.getY() << "]";
}

/// overloading of + operator using already implemented += overloading
CartVec2D operator+(const CartVec2D &lhs, const CartVec2D &rhs)
{
   CartVec2D result;
   result += lhs;
   result += rhs;
   return result;
}

/// overloading of - operator using already implemented -= overloading
CartVec2D operator-(const CartVec2D &lhs, const CartVec2D &rhs)
{
   CartVec2D result;
   result -= lhs;
   result -= rhs;
   return result;
}

/// overloading of - operator to product sign change of values in CartVec2D object
CartVec2D operator-(const CartVec2D &rhs)
{
   CartVec2D result;
   result -= rhs;
   return result;
}

/// overloading of += operator
CartVec2D &CartVec2D::operator+=(const CartVec2D &rhs)
{
   x_ += rhs.x_;
   y_ += rhs.y_;
   return *this;
}

/// overloading of -= operator
CartVec2D &CartVec2D::operator-=(const CartVec2D &rhs)
{
   x_ -= rhs.x_;
   y_ -= rhs.y_;
   return *this;
}

/// overloading of *= operator
CartVec2D &CartVec2D::operator*=(const CartVec2D &rhs){
   x_ *= rhs.x_;
   y_ *= rhs.y_;
   return *this;
}

/// overloading of * operator using already implemented *= overloading
CartVec2D operator*(const CartVec2D &lhs, const double &rhs)
{
   CartVec2D result;
   result = lhs;
   result.x_ *= rhs;
   result.y_ *= rhs;
   return result;
}

/// second overloading of * operator using already implemented *= overloading
CartVec2D operator*(const double &lhs, const CartVec2D &rhs)
{
   CartVec2D result;
   result = rhs;
   result.x_ *= lhs;
   result.y_ *= lhs;
   return result;
}
