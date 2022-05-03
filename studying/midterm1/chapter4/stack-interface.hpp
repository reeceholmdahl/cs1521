#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

template <typename T>
class Stack {
public:

  /* Virtual destructor */
  virtual ~Stack();

  virtual void push(const T& item) = 0;

  virtual T pop() = 0;

  virtual void unshift(const T& item) = 0;
  
  virtual T shift() = 0;
};

#endif // STACK_INTERFACE_
