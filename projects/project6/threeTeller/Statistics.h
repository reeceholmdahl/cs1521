#ifndef STATISTICS_
#define STATISTICS_

//#define TESTING

#include "../Event.h"
#include "../LinkedQueue.h"

class Statistics {
private:
   int countTotal = 0;

   int count1 = 0;
   int count2 = 0;
   int count3 = 0;

   Time waitTimeTotal = 0;

   Time waitTime1 = 0;
   Time waitTime2 = 0;
   Time waitTime3 = 0;

   /** Arrival events get stored until we encounter the next departure
    *  event.  This arrival along with the departure are then used to
    *  generate the wait time of this arrival. */
   LinkedQueue<Event> arrivalEvents1;
   LinkedQueue<Event> arrivalEvents2;
   LinkedQueue<Event> arrivalEvents3;

public:
   Statistics() = default;

   virtual ~Statistics() = default;

   /** Adds 'event' to the statistics collected so far.
    *
    * If 'event' is an arrival event, increment 'countTotal' and the
    * count associated with the line this customer is in and store it
    * for use with the next departure event.
    *
    * If 'event' is a departure event, calculate the wait time for
    * this customer and add it onto 'waitTimeTotal' and add it to the
    * wait time associated with the line this customer was in. */
   void addEvent(const Event& event);

   /** Output a report of the statistics for this simulation. */
   void reportStats() const;
};

#endif
