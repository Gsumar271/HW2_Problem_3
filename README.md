# HW2_Problem_3
HW 2 Problem 3
HW 2 PROBLEM 3
YEVGENIY SUMARYEV
 
In this problem we were to test which was faster, array based stack or a linked list based stack. I used standard array based and
linked list based stack, those classes in turn were derived from stackADT data type virtual class. In the main method I had a
timing function to time how elements are being inserted into the stack and how elements are being deleted from the stack I used 
a templated functions BuildArray() and BuildList() to build stack using random elements within some specified range and a templated 
function RemoveArray() and RemoveList() to remove elements from the stack, I’ve also used a templated timing function and used it as
a lambda because it was a convenient way to run a time test. After running the test on 1 million element, the results showed array based
stack was much faster than linked list stack, for inserting elements array stack performed about 4 times faster and when removing an element 
using pop() function array based stack was nearly 10 times faster. This showed me that array based stacks work much faster than the linked 
list based stacks and thus there was a clear advantage to use array based stack whenever possible 
