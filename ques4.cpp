//November 9, 2020
//Student name: Tania Chowdhury
//Professor’s name: Matthew Fried
//Course: CSCI313(48186)

#include<iostream>
#include<stack>
using namespace std;
template <typename T>
void displayStack(stack<T> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
    int x = s.top();
    // Pop the top element of the stack
    s.pop();
    // Recursively call the function displayStack
    displayStack(s);
    // Print the stack element starting
    // from the bottom
    cout << x << " ";
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}
template <typename T>
void changeValueBasedOnPosition(stack<T> & s,T v, int p)
{
    //check position is valid or invalid
    if (p > s.size() || p <= 0)
    {
        return;
    }
    //push element on top of stack
    if (p == s.size())
    {
        s.pop();
        s.push(v);
        return;
    }
    //array to store poped elements
    T* ptr = new T[s.size() - p];
    int i = 1;
    int size = s.size() - p;
    //store elements in array after popinng form stack
    for (i = 1; i <=size ; i++)
    {
        ptr[i - 1] = s.top();
        s.pop();
    }
    s.pop();
    //push value on the required position
    s.push(v);
    //push elements from array to stack
    for (i = i-1 ; i >= 1; i--)
    {
        s.push(ptr[i-1]);
    }
}
int main()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    displayStack(s);
    changeValueBasedOnPosition(s,10,1);
    displayStack(s);
    return 0;
}
