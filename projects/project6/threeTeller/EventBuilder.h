#ifndef EVENT_BUILDER_
#define EVENT_BUILDER_

#include <fstream>

#include "../Event.h"

class EventBuilder {
private:
   std::ifstream inputFile;

public:
   /** Three things must happen to create an EventBuilder:
    *  1) Prompt the user for the name of an input file
    *  2) Attempt to open this file on the 'inputFile' data member
    *  3) If the file doesn't open, repeat steps 1 and 2 */
   EventBuilder();

   /** Create and return an event with members:
    *  type == EventType::ARRIVAL
    *  number == input argument 'number'
    *  line == input argument 'lineNumber'
    *  time == time read from 'inputFile'
    *  duration == transaction length read from 'inputFile'
    *
    *  If 'inputFile' has been completely read (EOF has been reached),
    *  then set the return event.type field to EventType::NONE.  This
    *  can then be used to tell when the external file is either empty
    *  or EOF has been reached. */
  Event createArrivalEvent(int number);

  /** Create and return an event with members:
    *  type == EventType::DEPATURE
    *  number == input argument 'number'
    *  line == input argument 'lineNumber'
    *  time == 'currentEventTime' + 'transactionLength' */
   Event createDepartureEvent(const Time& currentEventTime,
                              const Time& transactionLength,
                              int number,
                              int lineNumber);
};

#endif
