## OPTIMAL - TC = O(1)

- Init 'top' ptr to -1 at start.
- With help of it, you can easily manipulate data from stack.

```cpp
#include<bits/stdc++.h>

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
    int top();
    int size();
    bool isEmpty();
};

//Function to push an integer into the stack.
void MyStack :: push(int x){
    top++;
    arr[top] = x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop(){
    if(top == -1) return -1;
    return arr[top--];       
}

// return top element
int MyStack :: top(){
    return arr[top];
}

// return size
int MyStack :: size(){
    return top+1;
}

// check if stack is empty
bool MyStack :: isEmpty(){
    return (top == -1);
}

```
