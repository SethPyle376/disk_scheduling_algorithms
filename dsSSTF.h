/***********************************************************************
* Component:
*    DISK SCHEDULING SSTF
* Author:
*    <your name here>
* Summary: 
*    This is the DERRIVED class to implement the SSTF algorithm
************************************************************************/

#ifndef DS_SSTF
#define DS_SSTF

#include "ds.h"   // for the DiskSchedulingAlgorithm base-class
#include <cmath>
// using namespace std;

/****************************************************
 * SSTF
 * The Sortest-Seek-Time-First disk scheduling algorithm
 ***************************************************/
class DiskSchedulingSSTF : public DiskSchedulingAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to SSTF
    *****************************************************/
   DiskSchedulingSSTF(const ScheduleProblem & problem) :
             DiskSchedulingAlgorithm(problem)
   {
      /////////////// YOUR CODE HERE ////////////////////
      requests = problem.requests;
   }

   int findClosest(int head)
   {
      int target = -1;
      int distance = 1000;

      std::list <int> :: iterator it;
      for (it = requests.begin(); it != requests.end(); ++it)
      {
         if (std::abs(head - *it) < distance)
         {
            target = *it;
            distance = std::abs(head - *it);
         }
      }
      return target;
   }
                

   /****************************************************
    * RUN
    * Implement the algorithm here. This function will only
    * be called once and will need to complete the entire
    * simulation.
    *
    * Each time a disk request is made by setting currentLocation,
    * call record() to save that.
    ***************************************************/
   void run()
   {
      /////////////// YOUR CODE HERE ////////////////////
      while (!requests.empty())
      {
         currentLocation = findClosest(currentLocation);
         requests.remove(currentLocation);
         record();
      }
      return;
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
   std::list <int> requests;
};

#endif // DS_SSTF
