/**********************************************************
             RUN IN COMMANDPROMPT WITH: ex08
**********************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "dofxyrz.h"
#include "rotationmotor.h"
#include "commandprocessor.h"
#include "cartvec2d.h"

// See buildmap for plotted diagrams

int main()
{
   const double PI{3.14159265358979323846};

   const double DELTA_t_sec{0.07}; // Simulation time step of 0.07 sec gets close to reality
   const double MAX_t_sec{10.0};
   double velocity{0.2}; // m/sec
   double angularVelocity{0.25 * PI}; // rad/sec
   double t_sec = 0.0;

   DOFxyRz roomba;

   std::ofstream csv_out("roombaCoordinates.csv");

      // Simulation loop
   while (t_sec <= MAX_t_sec)

   {
    std::cout << "t = " << std::setprecision(2) << std::fixed << t_sec << " " << roomba << '\n';

    // Calculate rotation every simulation step
    roomba += ((angularVelocity) * DELTA_t_sec);

    // Calculate translation every simulation step
    CartVec2D delta_heading(roomba.heading() * (velocity) * DELTA_t_sec);
    roomba += delta_heading;

    t_sec += DELTA_t_sec;

    csv_out <<  std::setprecision(2) << std::fixed << t_sec << "," << std::setprecision(2) << std::fixed
             << roomba.vector_2d.get_x() << "," << std::setprecision(2) << std::fixed << roomba.vector_2d.get_y()
             << '\n';
   }
   csv_out.close();
   return 0;
}









