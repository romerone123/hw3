#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap;
  int m;
	PComparator comp;

  void trickleUp();
  void trickleDown();

};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return heap[0]; //returns the top element


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  
  heap[0] = heap.back(); //swaps the bottom element with the top
  heap.pop_back(); //gets rid of the previously top element
  trickleDown(); // puts element in correct position
}


template <typename T, typename PComparator> //initializer that also give the values to our private data members
Heap<T,PComparator>::Heap(int m, PComparator c) : m(m), comp(c) {} 

template <typename T, typename PComparator> //Destructor
Heap<T,PComparator>::~Heap() 
{
  for(int i = heap.size() - 1; i >= 0; i--)
	{
		heap.pop_back();
	}
}



template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  heap.push_back(item);
  trickleUp();

  /*// print the vector
  std::cout << "Heap vector: " << std::endl;
  for (int i = 0; i < heap.size(); i++) 
  {
    std::cout << heap[i] << std::endl;
  }
*/
}


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return heap.empty();
}



template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return heap.size();
}



template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp()
{
	int newIndex = heap.size() - 1; //start at the end of the heap
	int parent = (newIndex - 1)/m; //parent index = (i-1) / m
	while(comp(heap[newIndex], heap[parent]) && newIndex > 0 ) //if newIndex = 0 that means we it is at the top of heap and it is done
	{
		std::swap(heap[newIndex], heap[parent]); //swap the values
		newIndex = parent;
		parent = (newIndex - 1)/m;
	}
}



template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown()
{
  int parent = 0;
  int bestChild = (parent * m) + 1;
  int otherChild = bestChild + 1;

  while(bestChild < heap.size())
  {
    for(int i = 0; i < m-1; i++) //we want to find the min or max child from the parent
    {
      if(comp(heap[bestChild], heap[otherChild + i]))
      {

      }
      else
      {
        bestChild = otherChild + i;
      }
    }

    if(comp(heap[bestChild], heap[parent])) //if the bestChild is better than the parent, swap them
    {
      std::swap(heap[bestChild], heap[parent]);
      parent = bestChild;
      bestChild = (parent * m) + 1;
      otherChild = bestChild + 1;
    }
    else 
    {
      break; //if the bestChild isn't better than the parent, then it is in the correct order
    }
  }

}


#endif

