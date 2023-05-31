#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
private:
    stack<int> inStack;
    stack<int> outStack;

public:
    void push(int x)
    {
        inStack.push(x);
    }

    int pop()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int frontElement = outStack.top();
        outStack.pop();
        return frontElement;
    }

    int peek()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    bool empty()
    {
        return inStack.empty() && outStack.empty();
    }
};

int main()
{
    // Create an instance of the MyQueue class
    MyQueue myQueue;

    // Push elements into the queue
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Get and print the front element
    int frontElement = myQueue.peek();
    cout << "Front Element: " << frontElement << endl;

    // Pop an element from the queue
    int poppedElement = myQueue.pop();
    cout << "Popped Element: " << poppedElement << endl;

    // Check if the queue is empty
    bool isEmpty = myQueue.empty();
    cout << "Is Queue Empty? " << (isEmpty ? "Yes" : "No") << endl;

    return 0;
}
//Time:O(1)
//Space:O(n)