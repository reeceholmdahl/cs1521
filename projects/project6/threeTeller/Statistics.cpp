#include <iostream>

#include "Statistics.h"

void Statistics::addEvent(const Event& event) {

   if (event.getType() == EventType::ARRIVAL) {
#ifdef TESTING
      std::cout << "Processing arrival event "
                << event.getNumber()
                << " in queue "
                << event.getLine()
                << " at time "
                << event.getTime()
                << std::endl;
#endif

#ifndef TESTING
      std::cout << ".";

      if (event.getNumber() % 72 == 0)
         std::cout << std::endl;
#endif

      ++countTotal;

      if (event.getLine() == 1) {
         arrivalEvents1.enqueue(event);
         ++count1;
      }
      else if (event.getLine() == 2) {
         arrivalEvents2.enqueue(event);
         ++count2;
      }
      else {
         arrivalEvents3.enqueue(event);
         ++count3;
      }
   }

   // Use departures to calculate total wait time and cumulative wait
   // time for each line.
   else {
#ifdef TESTING
      std::cout << "Processing departure event "
                << event.getNumber()
                << " at time: "
                << event.getTime()
                << " in line number "
                << event.getLine();
#endif
      Event arrivalEvent;
      bool eventWaiting(false);

      if (event.getLine() == 1 && !arrivalEvents1.isEmpty() ) {
         arrivalEvent = arrivalEvents1.peekFront();
         arrivalEvents1.dequeue();
         waitTime1 += event.getTime() -
            (arrivalEvent.getTime() + arrivalEvent.getDuration() );
         eventWaiting = true;
      }
      else if (event.getLine() == 2 && !arrivalEvents2.isEmpty() ) {
         arrivalEvent = arrivalEvents2.peekFront();
         arrivalEvents2.dequeue();
         waitTime2 += event.getTime() -
            (arrivalEvent.getTime() + arrivalEvent.getDuration() );
         eventWaiting = true;
      }
      else if (event.getLine() == 3 && !arrivalEvents3.isEmpty() ) {
         arrivalEvent = arrivalEvents3.peekFront();
         arrivalEvents3.dequeue();
         waitTime3 += event.getTime() -
            (arrivalEvent.getTime() + arrivalEvent.getDuration() );
         eventWaiting = true;
      }

      if (eventWaiting) {
#ifdef TESTING
         std::cout << " event "
                   << arrivalEvent.getNumber()
                   << " waited: "
                   << event.getTime() -
            (arrivalEvent.getTime() + arrivalEvent.getDuration() );
#endif
         waitTimeTotal += event.getTime() -
            (arrivalEvent.getTime() + arrivalEvent.getDuration() );
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
             << countTotal
             << std::endl;

   std::cout << "\tTotal wait time: "
             << waitTimeTotal
             << std::endl;

   std::cout << "\tAverage amount of time spent waiting: ";
   if (countTotal != 0) {
      std::cout << (double)waitTimeTotal / (double)countTotal;
   }
   else {
      std::cout << 0.0;
   }
   std::cout << std::endl;

   std::cout << "\n\tTotals for Teller 1:"
             << std::endl;

   std::cout << "\t\tPeople processed: "
             << count1
             << std::endl;

   std::cout << "\t\tWait time: "
             << waitTime1
             << std::endl;

   std::cout << "\t\tAverage wait time: ";
   if (count1 != 0) {
      std::cout << (double)waitTime1 / (double)count1;
   }
   else {
      std::cout << 0.0;
   }
   std::cout << std::endl;

   std::cout << "\n\tTotals for Teller 2:"
             << std::endl;

   std::cout << "\t\tPeople processed: "
             << count2
             << std::endl;

   std::cout << "\t\tWait time: "
             << waitTime2
             << std::endl;

   std::cout << "\t\tAverage wait time: ";
   if (count2 != 0) {
      std::cout << (double)waitTime2 / (double)count2;
   }
   else {
      std::cout << 0.0;
   }
   std::cout << std::endl;

   std::cout << "\n\tTotals for Teller 3:"
             << std::endl;

   std::cout << "\t\tPeople processed: "
           << count3
           << std::endl;

   std::cout << "\t\tWait time: "
             << waitTime3
             << std::endl;

   std::cout << "\t\tAverage wait time: ";
   if (count3 != 0) {
      std::cout << (double)waitTime3 / (double)count3;
   }
   else {
      std::cout << 0.0;
   }
   std::cout << std::endl;
}
