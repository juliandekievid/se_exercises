#include <map>
#include "commandprocessor.h"
#include "rotationmotor.h"


/*!
  overloaded constructor
  - adding commands of class RotationMotor to map commands_
*/


CommandProcessor::CommandProcessor(RotationMotor &rm)
{
   commands_["DEC_RPM"]     =  [&rm](){rm.decRPM(10);};
   commands_["INC_RPM"]     =  [&rm](){rm.incRPM(10);};
   commands_["RESTART"]     =  [&rm](){rm.restart();};
   commands_["SHUTDOWN"]    =  [&rm](){rm.shutDown();};
   commands_["GET_RPM"]     =  [&rm](){rm.getRPM();};
}


CommandProcessor::~CommandProcessor(){}


//   adds command of class RotationMotor to the map commands_

void CommandProcessor::addCommand(const std::string &command, const std::function<void()> cf)
{
   commands_[command]= cf;
}


//  member function which executes requested functions stored in map commands_

void CommandProcessor::executeCommand(const std::string &command)
{
   // p is an iterator
   auto p = commands_.find(command);
   if(p != end(commands_))
   {
      auto commandfunc = (*p).second;
      commandfunc();
   }
      else
      {
         /// display std::cerr when wrong option is inputted
         std::cerr << "\nUnknown option, try again\n";
      }
   }
