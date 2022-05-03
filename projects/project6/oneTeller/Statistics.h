#ifndef STATISTICS_
#define STATISTICS_

#define TESTING

#include "../Event.h"
#include "../LinkedQueue.h"

class Statistics {
private:
   int count = 0;

   Time waitTime = 0;

   /** Arrival events get stored until we encounter the next departure
    *  event.  This arrival along with the departure are then used to
    *  generate the wait time of this arrival. */
   LinkedQueue<Event> arrivalEvents;

public:
   Statistics() = default;

   virtual ~Statistics() = default;

   /** Adds 'event' to the statistics collected so far.
    *
    * If 'event' is an arrival event, increment 'count' and store it
    * for use with the next departure event.
    *
    * If 'event' is a departure event, calculate the wait time for
    * this customer and add it onto 'waitTime'. */
   void addEvent(const Event& event);

   /** Output a report of the statistics for this simulation. */
   void reportStats() const;
};

#endif
