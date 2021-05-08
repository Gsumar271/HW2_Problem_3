//Header file: myStack.h
#ifndef H_StackType 
#define H_StackType
 
#include <iostream> 
#include <cassert>

#include "stackADT.h"
 
using namespace std;


//stack class that uses array
//uses 2 additional methods
//oone for replacing the element 
//at certain position, and another 
//to print the contents of the stack 
template <class Type>
class stackType: public stackADT<Type>
{
public:

    //Overload the assignment operator.
    const stackType<Type>& operator=(const stackType<Type>&); 
    
    //Function to initialize the stack to an empty state. 
    void initializeStack();
      
    //Function to determine whether the stack is empty.
    bool isEmptyStack() const;
      
    //Function to determine whether the stack is full.
    bool isFullStack() const;
      
    //Function to add newItem to the stack.
    void push(const Type& newItem);

    //Function to return the top element of the stack.
    Type top() const;
      
    //Function to remove the top element of the stack.
    void pop();

    //function that iterates through the stack
    //and replaces an element in the stack
    //based on its position 
    void replace(int pos, const Type& newItem);

    //function to list all the elements in the stack
    void printStack();

    //constructor
    //Create an array of the size stackSize to hold 
    //the stack elements. The default stack size is 100.
    stackType(int stackSize = 100); 
      
    //copy constructor
    stackType(const stackType<Type>& otherStack); 
      
    //destructor
    //Remove all the elements from the stack.
    ~stackType(); 

private:
    //variable to store the maximum stack size
    int maxStackSize; 
    //variable to point to the top of the stack
    int stackTop;   
    //pointer to the array that holds the
    //stack elements
    Type *list;       
                      
    //Function to make a copy of otherStack.
    void copyStack(const stackType<Type>& otherStack); 
};


//initializes the stack 
template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}//end initializeStack

//checks if stack is empty 
template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return (stackTop == 0);
}//end isEmptyStack

//checks if stack is full
template <class Type>
bool stackType<Type>::isFullStack() const
{
    return (stackTop == maxStackSize);
} //end isFullStack

//add new item at the top of the stack 
template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
        //adds the item 
        list[stackTop] = newItem;    
        //increments stackTop                  
        stackTop++; 
    }
    else
        cout << "Cannot add to a full stack." << endl;
}//end push

//get the top of the stack 
template <class Type>
Type stackType<Type>::top() const
{
    //if stack is empty 
    //terminate the program
    assert(stackTop != 0);    
    //return the element of the
    //stack indicated by 
    //stackTop - 1  
    return list[stackTop - 1];  
}//end top

//delete the top element of the stack 
template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
        //decrement stackTop 
        stackTop--;      
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

//replace a specific item in the array 
//according to it's position 
template <class Type>
void stackType<Type>::replace(int pos, const Type& newItem)
{
    //may do this by adding position to the pointer
    //*(list + pos) = newItem;

    //otherwise use iteration 
    int i=0;
    //iterate through array 
    //until necessary position is reached
    while(i < pos)
      i++;
    //replace the item with new item
    list[i] = newItem;
    
}

//print the contents of the array 
template<class Type>
void stackType<Type>::printStack(){
    for (int i = 0; i < stackTop; i++)
    {
        cout << *(list + i) << " ";
    }
    cout << endl;
}

//constructor of the array class
template <class Type>
stackType<Type>::stackType(int stackSize) 
{
    if (stackSize <= 0)
    {
        cout << "Size of the array must be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        //set the stack size to 
        //the value specified by
        //the parameter stackSize
        maxStackSize = stackSize;   
                                    
    //set stackTop to 0
    stackTop = 0;                   
    //create new array to hold the elements of the stack 
    list = new Type[maxStackSize];  
}//end constructor

//destructor
template <class Type>
stackType<Type>::~stackType() 
{
    //deallocate the memory used
    //by the array
    delete [] list; 
}//end destructor

//copy the stack 
template <class Type>
void stackType<Type>::copyStack
                (const stackType<Type>& otherStack)
{ 
    //delete previous array 
    delete [] list;	
    //copy all the properties of other stack
    //into this new stack 
    maxStackSize = otherStack.maxStackSize;	
    stackTop = otherStack.stackTop;	
	  
    //create new array stack 
    list = new Type[maxStackSize];

    //copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)  
        list[j] = otherStack.list[j];
} //end copyStack


//copy constructor
template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = nullptr;

    copyStack(otherStack);
}//end copy constructor

//overload = operator 
//so that one stack can be assigned to another
template <class Type>
const stackType<Type>& stackType<Type>::operator=
                            (const stackType<Type>& otherStack)
{ 
    //to avoid self-copy 
    if (this != &otherStack) 
        copyStack(otherStack);

    return *this; 
} //end operator=         

#endif