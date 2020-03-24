#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <functional>
#include <iostream>
#include <map>
#include <utility>


class RotationMotor;

class CommandProcessor
{
private:
   /// wrap function, calls memberfunctions of class RotationMotor
   using commandfunction = std::function<void()>;

   /// map in which strings are linked to commands of class RotationMotor
   std::map<std::string, commandfunction> commands_;

public:
   CommandProcessor(RotationMotor &rm);
   ~CommandProcessor();

   /// executes commands which are given by user input and looks them up in the map commands_
   void executeCommand(const std::string &command);
   void addCommand(const std::string commandInput, const std::function<void()> commandToAdd);
};

#endif // COMMANDPROCESSOR_H
