// My ID: 5727889
#include <new>
#include <iostream>

#include "isPalindrome.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

bool isPalindrome(const std::string& aString) {

  try {
    LinkedStack<char> stack;
    LinkedQueue<char> queue;
  
    for (char c : aString) {
      stack.push(c);
      queue.enqueue(c);
    }

    while (!stack.isEmpty() ) {
      if (stack.peek() == queue.peekFront() ) {
	stack.pop();
	queue.dequeue();
      } else {
	return false;
      }
    }

    return true;
  } catch (const std::bad_alloc&) {
    std::cerr << "Memory allocation error. Exiting." << std::endl;
    return false;
  }
}
