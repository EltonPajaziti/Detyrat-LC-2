#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x)
    {
        q.push(x);
        int size = q.size();
        while (size > 1)
        {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    int pop()
    {
        int top = q.front();
        q.pop();
        return top;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    // Create an instance of the MyStack class
    MyStack stack;

    // Push elements into the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Get the top element
    cout << "Top element: " << stack.top() << endl;

    // Pop elements from the stack
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    // Check if the stack is empty
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;

    return 0;
}
/*Time complexity: O(n) for push operation, O(1) for pop, top, and empty operations.
Space complexity: O(n), where n is the number of elements in the stack.*/