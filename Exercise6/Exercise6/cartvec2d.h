#ifndef CARTVEC2D_H
#define CARTVEC2D_H

#include <ostream>

/// CartVec2d represents a 2D Cartesian vector.
class CartVec2D
{
   // The global operator functions are made friend of this class so
   // that it can access private members
   friend std::ostream& operator<<(std::ostream &os, const CartVec2D &rhs);
   friend CartVec2D operator+(const CartVec2D &lhs, const CartVec2D &rhs);
   friend CartVec2D operator-(const CartVec2D &lhs, const CartVec2D &rhs);
   friend CartVec2D operator-(const CartVec2D &rhs);
   friend CartVec2D operator*(const CartVec2D &lhs, const double &rhs);
   friend CartVec2D operator*(const double &rhs, const CartVec2D &lhs);

public:
   CartVec2D(double x, double y): x_(x), y_(y){}
   /// Using C++11 constructor delegation for the default constructor.
   CartVec2D(): CartVec2D(0.0, 0.0){}
   /// Default copy constructor.
   CartVec2D(const CartVec2D &other) = default;

   /// with inline functions, the compiler does not have to jump to another location to execute the function,
   /// and then jump back as the code of the called function is already available to the calling program.

   /// getter x_
   inline double getX() const{return x_;}

   ///getter y_
   inline double getY() const{return y_;}

   ///setter y_
   inline void setY(const double y){y_=y;}

   ///setter x_
   inline void setX(const double x){x_=x;}

   /// Default assignment operator.
   CartVec2D& operator=(const CartVec2D &other) = default;

   /// Default destructor.
   ~CartVec2D() = default;

   // += and -= operators are class member functions.
   CartVec2D &operator+=(const CartVec2D &rhs);
   CartVec2D &operator-=(const CartVec2D &rhs);
   CartVec2D &operator*=(const CartVec2D &rhs);

   /// Magnitude of vector.
   double length() const;

private:
   double x_; // Naming convention class data members, use _ suffix.
   double y_;
};

#endif // CARTVEC2D_H

