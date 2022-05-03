#include <iostream>

#include "Statistics.h"

void Statistics::addEvent(const Event& event) {

   if (event.getType() == EventType::ARRIVAL) {
#ifdef TESTING
      std::cout << "Processing arrival event "
                << event.getNumber()
                << " at time: "
                << event.getTime()
                << std::endl;
#endif

#ifndef TESTING
      std::cout << ".";

      if (event.getNumber() % 72 == 0)
         std::cout << std::endl;
#endif
      arrivalEvents.enqueue(event);
      ++count;
   }
   else { // event is a departure event
#ifdef TESTING
      std::cout << "Processing departure event "
                << event.getNumber()
                << " at time: "
                << event.getTime();
#endif
      if (!arrivalEvents.isEmpty() ) {
         Event arrivalEvent;

         arrivalEvent = arrivalEvents.peekFront();
         arrivalEvents.dequeue();
         waitTime += event.getTime() -
            (arrivalEvent.getTime() + arrivalEvent.getDuration() );
#ifdef TESTING
         std::cout << " event "
                   << arrivalEvent.getNumber()
                   << " waited: "
                   << event.getTime() -
            (arrivalEvent.getTime() + arrivalEvent.getDuration() );
#endif
      }
#ifdef TESTING
      else {
         std::cout << " no events waiting.";
      }
      std::cout << std::endl;
#endif
   }
}

void Statistics::reportStats() const {

  std::cout << "Final Statistics:"
	    << std::endl;

  std::cout << "\tTotal number of people processed: "
	    << count
	    << std::endl;

  std::cout << "\tTotal wait time: "
	    << waitTime
	<< std::endl;

   std::cout << "\tAverage amount of time spent waiting: ";
   if (count != 0) {
      std::cout << (double)waitTime / (double)count;
   }
   else {
      std::cout << 0.0;
   }
   std::cout << std::endl;
}
