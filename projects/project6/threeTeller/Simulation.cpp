// My ID: 5727889
// Copying in oneTeller version

#include <iostream>

#include "Simulation.h"
#include "../Time.h"
#include "../EventType.h"

Simulation::Simulation() {
  std::cout << "Simulation of 3 Queue Begins" << std::endl;
}

LinkedQueue<Event>& Simulation::getLine(int lineNumber) {
  switch (lineNumber) {
  case 1:
    return line1;
  case 2:
    return line2;
  case 3:
    return line3;
  default:
    return line1;
  }
}

void Simulation::processArrival() {

  // Determine the smallest line to queue the next arrival in
  int lineToQueue;
  if (line1.getLength() <= line2.getLength() && line1.getLength() <= line3.getLength() ) {
    // Line 1 is the shortest
    lineToQueue = 1;
  } else if (line2.getLength() <= line1.getLength() && line2.getLength() <= line3.getLength() ) {
    // Line 2 is the shortest
    lineToQueue = 2;
  } else {
    // Line 3 is the shortest
    lineToQueue = 3;
  }

  // Set the line this event is in to the smallest line found
  currentEvent.setLine(lineToQueue);

  // Alias to the smallest line
  LinkedQueue<Event> &line = getLine(lineToQueue);
  
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
						      currentEvent.getNumber(),
						      currentEvent.getLine()
						      ));
    
    events.enqueue(departure);
  }
  
  // Add next arrival to events queue
  Event nextArrival = eventBuilder.createArrivalEvent(currentEvent.getNumber() + 1);

  // If the event is valid, meaning input stream hasn't reached end of file then add it to events
  if (nextArrival.getType() != EventType::NONE) {
    events.enqueue(nextArrival);
  }
}

void Simulation::processDeparture() {

  LinkedQueue<Event> &line = getLine(currentEvent.getLine() );
  
  // Remove customer from front of line
  line.dequeue();

  // Remove this departure event from front of events queue
  events.dequeue();

  // If the line isn't empty, enqueue a departure event for the customer at front of line.
  if (!line.isEmpty()) {
    Event front(line.peekFront());
    
    events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
						     front.getDuration(),
						     front.getNumber(),
						     front.getLine()
						     ));
  }
}

void Simulation::simulate() {

  // Event number 1, line number 1
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
