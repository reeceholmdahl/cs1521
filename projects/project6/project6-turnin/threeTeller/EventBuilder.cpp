// My ID: 5727889
// This file is part of the threeTeller version
#include <iostream>

#include "EventBuilder.h"
#include "../Time.h"
#include "../EventType.h"

EventBuilder::EventBuilder() {
  while(true) {
    std::cout << "Input file name: ";

    std::string fileName;
    std::cin >> fileName;

    inputFile.open(fileName);

    // If cannot open, continue loop at start and try again
    if (!inputFile) {
      std::cout << "Could not open file '" << fileName << "'. Please try again." << std::endl;
      continue;
    }

    // If properly opened, add a linebreak and exit loop; construction is complete
    std::cout << std::endl;
    break;
  }
}

Event EventBuilder::createArrivalEvent(int number) {
  Event event;
  Time time;
  Time duration;
  
  inputFile >> time;
  inputFile >> duration;

  // Set the event's line to arbitrary; it will be set elsewhere
  event.setLine(-1);

  // If the input file stream is good, attribute inputs to the event
  if (inputFile.good()) {
    event.setType(EventType::ARRIVAL);
    event.setTime(time);
    event.setDuration(duration);
    event.setNumber(number);
  }

  return event;
}

Event EventBuilder::createDepartureEvent(const Time& currentEventTime, const Time& transactionLength, int number, int line) {
  Event departure(EventType::DEPARTURE, currentEventTime + transactionLength, 0, number, line);
  return departure;
}
