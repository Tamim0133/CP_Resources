#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *nxt;
    Node *prev;

    Node(int val)
    {
        data = val;
        nxt = NULL;
        prev = NULL;
    }
};

class Stack
{
    Node *head;
    Node *top;
    int sz = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }

    // O(1)
    void PUSH(int val)
    {
        sz++;
        Node *nwNode = new Node(val);
        if (head == NULL)
        {
            head = top = nwNode;
            return;
        }
        top->nxt = nwNode;
        nwNode->prev = top;
        top = nwNode;
    }
    // O(1)
    void POP()
    {
        Node *delNode = top;
        if (top == head)
        {
            head = top = NULL;
        }
        else
        {
            top = delNode->prev;
            top->nxt = NULL;
        }
        delete delNode;
        sz--;
    }
    // O(1)
    bool EMPTY()
    {
        if (sz == 0)
            return true;
        return false;
    }

    // O(1)
    int SIZE()
    {
        return sz;
    }

    // O(1)
    int TOP()
    {
        return top->data;
    }
};
int main()
{
    Stack numst;
    numst.PUSH(10);
    numst.PUSH(20);
    numst.PUSH(30);
    numst.PUSH(40);
    numst.PUSH(50);
    numst.PUSH(60);
    numst.PUSH(70);
    numst.PUSH(80);
    // cout << numst.EMPTY();
    // cout << numst.SIZE();
    cout << "size: " << numst.SIZE() << '\n';

    while (numst.EMPTY() == false)
    {
        cout << numst.TOP() << " ";
        numst.POP();
    }
    cout << "\nsize: " << numst.SIZE() << '\n';

    return 0;
}