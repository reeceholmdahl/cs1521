// My ID: 5727889

#include <iostream>

#include "Simulation.h"
#include "../Time.h"
#include "../EventType.h"

Simulation::Simulation() {
  std::cout << "Simulation of 1 Queue Begins" << std::endl;
}

void Simulation::processArrival() {

  // Line empty?
  bool lineIsEmpty(line.isEmpty());
  
  // Add event to the line
  line.enqueue(currentEvent);

  // Dequeue from the event list
  events.dequeue();

  // Add a departure event to the event list if the line was empty
  if (lineIsEmpty) {    
    Event departure(eventBuilder.createDepartureEvent(currentEvent.getTime(),
						      currentEvent.getDuration(),
						      currentEvent.getNumber()
						      ));
    
    events.enqueue(departure);
  }

  // Add next arrival event, -1 number arbitrary for now
  Event nextArrival = eventBuilder.createArrivalEvent(currentEvent.getNumber() + 1);

  // If the event is valid, meaning input stream hasn't reached end of file then add it to events
  if (nextArrival.getType() != EventType::NONE) {
    events.enqueue(nextArrival);
  }
}

void Simulation::processDeparture() {

  // Remove customer from front of line
  line.dequeue();

  // Remove this departure event from front of events queue
  events.dequeue();

  // If the line isn't empty, enqueue a departure event for the customer at front of line.
  if (!line.isEmpty()) {
    Event front(line.peekFront());
    
    events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
						     front.getDuration(),
						     front.getNumber()
						     ));
  }
}

void Simulation::simulate() {

  Event firstEvent = eventBuilder.createArrivalEvent(1);
  
  if (firstEvent.getType() != EventType::NONE) {
    events.enqueue(firstEvent);
  }
      
  while(!events.isEmpty()) {
    
    // Next event
    currentEvent = events.peekFront();

    if (currentEvent.getType() == EventType::ARRIVAL) {

      processArrival();
    } else { // The event is a departure event

      processDeparture();
    }

    // Add to statistics
    stats.addEvent(currentEvent);
  }

#ifndef TESTING
  std::cout << std::endl;
#endif

  std::cout << "Simulation Ends\n" << std::endl;

  // Report statistics
  stats.reportStats();
}
