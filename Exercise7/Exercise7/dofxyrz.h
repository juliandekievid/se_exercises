#ifndef DOFXYRZ_H
#define DOFXYRZ_H

#include <ostream>
#include "cartvec2d.h"

class DOFxyRz
{
   friend std::ostream& operator<<(std::ostream &os, const DOFxyRz &coordinate);

public:
   DOFxyRz();
   DOFxyRz(double x, double y);
   CartVec2D vector_2d;

   void showVector(const CartVec2D vector);
   double getRz_() const {return Rz_;}
   void setRz_(const double z_coordinate) { Rz_ = z_coordinate; }
   CartVec2D heading()const;

   DOFxyRz &operator+=(const CartVec2D &rhs);
   DOFxyRz &operator+(const CartVec2D &rhs);
   DOFxyRz &operator+(const double &rhs);
   DOFxyRz &operator-=(const CartVec2D &rhs);
   DOFxyRz &operator-(const CartVec2D &rhs);
   DOFxyRz &operator-(const double &rhs);

private:
   double Rz_{0};
   const double PI_{3.14159265358979323846};
};

#endif // DOFXYRZ_H
