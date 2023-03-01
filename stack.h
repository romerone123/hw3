#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: private std::vector<T> //private inheritance to std::vector
{
std::vector<T> stackObject; //vector object for stack

public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop(); // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

};

template <typename T>
Stack<T>::Stack(){} //Constructor


template <typename T>
bool Stack<T>::empty() const {

	if(stackObject.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
size_t Stack<T>::size() const {

	return stackObject.size();
}

template <typename T>
void Stack<T>::push(const T& item) {

	stackObject.insert(stackObject.begin(), item); //insert to front
}


template <typename T>
void Stack<T>::pop() {
		
	if(stackObject.empty())
	{
		throw std::underflow_error("The stack is empty");
	}
	stackObject.erase(stackObject.begin()); //pop from front
}

template <typename T>
T const & Stack<T>::top() const {

	if(stackObject.empty())
	{
		throw std::underflow_error("The stack is empty");
	}
	return stackObject[0];  //returns first item in vector
}

template <typename T>
Stack<T>::~Stack(){

	while(stackObject.empty() == false)
	{
		pop();  //pops entire vector
	}
}

#endif