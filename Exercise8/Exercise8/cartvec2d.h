#ifndef CARTVEC2D_H
#define CARTVEC2D_H

#include <ostream>

/// CartVec2d represents a 2D Cartesian vector.
class CartVec2D
{
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

   /// setter x_
   inline void set_x(const double x){x_=x;}

   /// setter y_
   inline void set_y(const double y){y_=y;}

   /// getter x_
   inline double get_x() const {return x_;}

   /// getter y_
   inline double get_y() const {return y_;}

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

