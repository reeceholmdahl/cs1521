// My ID: 5727889
// This file is part of the oneTeller version
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
   LinkedQueue<Event> line;
   PriorityQueue<Event> events;
   Statistics stats;

   void processArrival();
   void processDeparture();

public:
   Simulation();
   virtual ~Simulation() = default;

   void simulate();
};

#endif
