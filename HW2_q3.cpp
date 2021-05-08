#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <chrono>
#include "linkedStackType.h"
#include "stackType.h"

using namespace std;

using chrono::system_clock;
using chrono::steady_clock;
using chrono::duration_cast;
using chrono::seconds;
using chrono::milliseconds;


//test how fast array based stack
//inserts elements into the array
void BuildArray(stackType<int> &arr, int size){

    for (int i = 0; i < size; i++)
    {
        arr.push(rand() % 100 + 1);
    }

}

//test how fast linked list based stack 
//inserts elements into stack 
void BuildList(linkedStackType<int> &list, int size){

    for (int i = 0; i < size; i++)
    {
        list.push(rand() % 100 + 1);
    }
}

//test how fast array based stack
//removes elements from the array
void RemoveArray(stackType<int> &arr, int size){

    for (int i = 0; i < size; i++)
    {
        arr.pop();
    }

}

//test how fast linked list based stack 
//removes elements from the stack 
void RemoveList(linkedStackType<int> &list, int size){

    for (int i = 0; i < size; i++)
    {
        list.pop();
    }
}


//a timing function which takes a lambda function
//and times it's duration
//a very convenient way to pass any function to be tested
//in the process
template <typename func>
long long TimeFunc(func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();
}


int main() {

    //declare all necessary variables
    int x;
    //test the stack on the size of million elements
    int const size = 1000000;
    stackType<int> arrayStack(1000000);
    linkedStackType<int> linkedListStack;
    
    //test how fast the stack would be built
    //using array and then using linked list 
    auto arraymilliseconds = TimeFunc([&]() {BuildArray(arrayStack, size); });
    auto listmilliseconds = TimeFunc([&]() {BuildList(linkedListStack, size); });

    cout<<"Array stack insert time: " << arraymilliseconds << endl;
    cout<<"List stack insert time: "<< listmilliseconds << endl;

    //test how fast the stack would remove elements
    //first using array and then using linked list
    arraymilliseconds = TimeFunc([&]() {RemoveArray(arrayStack, size); });
    listmilliseconds = TimeFunc([&]() {RemoveList(linkedListStack, size); });

    cout<<"Array stack remove time: " << arraymilliseconds << endl;
    cout<<"List stack remove time: "<< listmilliseconds << endl;

    return 0;
}