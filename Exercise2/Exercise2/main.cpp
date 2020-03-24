#include <iostream>
#include <string>
#include "rotationmotor.h"

const std::string get_option();

int main()
{
   std::cout << "Welcome to this motor demonstration\n";
   // Initialize motor1
   int motor_speed = 0;
   std::string motor_option;
   RotationMotor motor1;

   do
   {
      // Get user input
      motor_option = get_option();

      // Handle user input in switch case structure
      if(motor_option == "START_MOTOR")
      {
         motor1.startMotor();
      }
      else if(motor_option == "INC_RPM")
      {
         motor1.incRPM(10);
      }
      else if(motor_option == "DEC_RPM")
      {
         motor1.decRPM(10);
      }
      else if(motor_option == "GET_RPM")
      {
         motor_speed = motor1.getRPM();
         std::cout << "Motorspeed: " << motor_speed << '\n';
      }
      else if(motor_option == "RESTART")
      {
         motor1.restart();
      }
      else if(motor_option == "SHUTDOWN")
      {
         motor1.shutDown();
      }
      else
      {
         std::cerr << "ERROR: You typed an unknown option, please try again\n";
      }
   }while(motor_option != "SHUTDOWN");
   return 0;
}

const std::string get_option()
{
   std::string option;
   std::cout << "Choose an option by typing it exact the same and pressing enter:\n"
                "- START_MOTOR\n- INC_RPM\n- DEC_RPM\n- GET_RPM\n- RESTART\n- SHUTDOWN\n";
   std::cout << "Choice: ";
   std::getline (std::cin, option);
   return option;
}
