// My ID: 5727889
// Master file, included in both oneTeller and threeTeller varieties
#include "Event.h"

Event::Event(EventType type, Time time, Time duration, int number, int line) {
  this->type = type;
  this->time = time;
  this->duration = duration;
  this->number = number;
  this->line = line;
}

EventType Event::getType() const {
  return type;
}

void Event::setType(EventType newType) {
  type = newType;
}

Time Event::getTime() const {
  return time;
}

void Event::setTime(Time newTime) {
  time = newTime;
}

Time Event::getDuration() const {
  return duration;
}

void Event::setDuration(Time newDuration) {
  duration = newDuration;
}

int Event::getNumber() const {
  return number;
}

void Event::setNumber(int newNumber) {
  number = newNumber;
}

int Event::getLine() const {
  return line;
}

void Event::setLine(int newLine) {
  line = newLine;
}
