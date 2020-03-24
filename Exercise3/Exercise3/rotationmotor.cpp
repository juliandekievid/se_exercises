#include <iostream>
#include "rotationmotor.h"

RotationMotor::RotationMotor()
{
   std::cout << "\nINFO: Default constructor RotationMotor() called\n\n";
   rpm = 0;
   start = false;
}

RotationMotor::~RotationMotor()
{
   std::cout << "\nINFO: Destruct1or called\n\n";
}

void RotationMotor::startMotor()
{
   std::cout << "\nINFO: Function startMotor() called\n\n";
   if(start == false)
   {
      start = true;
   }
   else
   {
      std::cout << "Motor already started...\n";
   }
}

void RotationMotor::shutDown()
{
   std::cout << "\nINFO: Function shutDown() called\nRPM is set to 0\n";
   if(start == true)
   {
      start = false;
      rpm = 0;
      exit(EXIT_SUCCESS);
   }
}

void RotationMotor::restart()
{
   std::cout << "\nINFO: Function restart() called\n\n";
   if(start == false)
   {
      std::cerr << "Error: you are trying to restart the motor, but the motor is not started yet.\nPlease type START_MOTOR\n";
   }
   else
   {
      start = true;
      rpm = 0;
   }
}

void RotationMotor::incRPM(const int speed)
{
   std::cout << "\nINFO: Function incRPM() called\n\n";
   int motorSpeed = 0;
   if(start == true)
   {
      rpm += speed;
      if (rpm > get_rpm_max())
      {
         int rpm_maximum = get_rpm_max();
         std::cout << "Rpm is limited to a maximum of " << rpm_maximum << '\n';
         rpm = rpm_max;
      }
      motorSpeed = getRPM();
      std::cout << "New rpm = " << motorSpeed << '\n';
   }
   else
   {
      std::cerr << "Error: You must first start the machine\n";
   }
}

void RotationMotor::decRPM(const int speed)
{
   std::cout << "\nINFO: Function decRPM() called\n\n";
   int motorSpeed = 0;
   if(start == true)
   {
      rpm -= speed;
      if (rpm < get_rpm_min())
      {
         int rpm_minimum = get_rpm_min();
         rpm = rpm_min;
         std::cout << "Rpm is limited to a minimum of " << rpm_minimum << '\n';
      }
      motorSpeed = getRPM();
      std::cout << "New rpm = " << motorSpeed << '\n';
   }
   else
   {
      std::cerr << "Error: You must first start the machine\n";
   }
}

// const is used to be sure the rpm value is not changed inside the getter function
int RotationMotor::getRPM() const
{
   std::cout << "\nINFO: Getter getRPM() called\n\n";
   return rpm;
}

int  RotationMotor::get_rpm_max() const
{
   std::cout << "\nINFO: Getter get_rpm_max() called\n\n";
   return rpm_max;
}

int  RotationMotor::get_rpm_min() const
{
   std::cout << "\nINFO: Getter get_rpm_min() called\n\n";
   return rpm_min;
}
