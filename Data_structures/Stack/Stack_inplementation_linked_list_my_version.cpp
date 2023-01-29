#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *stackNode = new Node;
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

class Stack
{
    Node *head;
    int sz;

public:
    Stack()
    {
        head = NULL;
        sz = 0;
    }

    void push(int data)
    {
        Node *temp = newNode(data);
        temp->next = head;
        head = temp;
        sz++;
    }

    int top()
    {
        if (head == NULL)
            return -1;
        else
            return head->data;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        head = head->next;
        sz--;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    int size() { return sz; }
};

int main()
{
    Stack st;

    cout << st.size() << endl;    // 0
    cout << st.isEmpty() << endl; // 1

    st.push(100);
    cout << st.top() << endl; // 100

    st.push(101);
    cout << st.top() << endl; // 101

    cout << st.isEmpty() << endl; // 0

    st.push(102);
    cout << st.top() << endl; // 102

    cout << st.size() << endl; // 3

    st.pop();
    cout << st.top() << endl; // 102

    st.pop();
    cout << st.top() << endl; // 100

    st.pop();                 //  kicchuna
    cout << st.top() << endl; // -1

    st.pop();

    cout << st.size() << endl;    // 0
    cout << st.isEmpty() << endl; // 1

    return 0;
}