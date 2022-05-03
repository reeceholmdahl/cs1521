// My ID: 5727889

#ifndef EVENT_
#define EVENT_

#include "EventType.h"
#include "Time.h"

class Event {
private:

  EventType type;
  Time time;
  Time duration;
  int number;
  int line;
  
public:

  /** Ctor with preset arguments */
  Event(EventType type = EventType::NONE, Time time = 0, Time duration = 0, int number = 0, int line = 1);

  /** Virtual (default) dtor */
  virtual ~Event() = default;

  /** Comparison operator overloads */
  bool operator<(const Event& rhs) const {
    return time < rhs.time;
  }

  bool operator>(const Event& rhs) const {
    return time > rhs.time;
  }

  bool operator==(const Event& rhs) const {
    return time == rhs.time;
  }

  /** Comparison operator overloads defined in terms of the previous three overloads */
  bool operator<=(const Event& rhs) const {
    return *this < rhs || *this == rhs;
  }

  bool operator>=(const Event& rhs) const {
    return *this > rhs || *this == rhs;
  }

  bool operator!=(const Event& rhs) const {
    return !(*this == rhs);
  }

  /** Accessor and mutator for 'type' */
  virtual EventType getType() const;

  virtual void setType(EventType newType);

  /** Accessor and mutator for 'time' */
  virtual Time getTime() const;

  virtual void setTime(Time newTime);

  /** Accessor and mutator for 'duration' */
  virtual Time getDuration() const;

  virtual void setDuration(Time newDuration);

  /** Accessor and mutator for 'number' */
  virtual int getNumber() const;

  virtual void setNumber(int newNumber);

  /** Accessor and mutator for 'line' */
  virtual int getLine() const;

  virtual void setLine(int newLine);
};

#endif // EVENT_
