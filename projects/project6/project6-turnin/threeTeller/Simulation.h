// My ID: 5727889
// This file is part of the threeTeller version
#ifndef SIMULATION_
#define SIMULATION_

#include "../Event.h"
#include "EventBuilder.h"
#include "../LinkedQueue.h"
#include "../PriorityQueue.h"
#include "Statistics.h"

class Simulation {
private:
   Event currentEvent;
   EventBuilder eventBuilder;
   LinkedQueue<Event> line1;
   LinkedQueue<Event> line2;
   LinkedQueue<Event> line3;
   PriorityQueue<Event> events;
   Statistics stats;

   void processArrival();
   void processDeparture();

   /** Get the linked queue of events associated with 'lineNumber'.
       @pre 'lineNumber' is either 1, 2, or 3. 
       @post None. 
      
       @param lineNumber The line's number to retrieve.
       @return A linked queue of events associated with 'lineNumber'. */
   LinkedQueue<Event>& getLine(int lineNumber);

public:
   Simulation();
   virtual ~Simulation() = default;

   void simulate();
};

#endif
