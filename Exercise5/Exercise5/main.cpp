#include <functional>
#include <iostream>
#include <map>
#include <utility>
#include <string>
#include "rotationmotor.h"

const std::string get_option();

int main()
{
   std::cout << "Welcome to this motor demonstration\n";
   std::string motor_option;
   RotationMotor motor1;

   CommandProcessor CP_motor1(motor1);
   CP_motor1.addCommand("START_MOTOR", [&motor1](){motor1.startMotor();});
   do{
      motor_option = get_option();
      CP_motor1.executeCommand(motor_option);
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
