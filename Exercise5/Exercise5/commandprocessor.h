#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <functional>
#include <iostream>
#include <map>
#include <utility>

class RotationMotor;

class CommandProcessor
{
public:
   CommandProcessor(RotationMotor &rm);
   ~CommandProcessor();

   using commandfunction = std::function<void()>;

private:
   std::map<std::string, commandfunction> commands_;

public:
   void addCommand(const std::string &command, CommandProcessor::commandfunction cf);
   void executeCommand(const std::string &command);

};

#endif // COMMANDPROCESSOR_H
