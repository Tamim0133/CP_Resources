#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 500;

class Queue
{
public:
    int a[MAX_SIZE];
    int l, r;
    int sz;
    Queue()
    {
        l = 0;
        r = -1;
        sz = 0;
    }

    void enqueue(int value) // O(1)
    {
        if (sz == MAX_SIZE)
        {
            cout << "Queue is full" << endl;
            return;
        }

        r++;

        if (r == MAX_SIZE) // এইখানে অনেক কাহিনী আছে ।
            r = 0;

        a[r] = value;
        sz++;
    }

    void dequeue() // O(1)
    {
        if (sz == 0)
        {
            cout << "Queue is empty " << endl;
            return;
        }
        l++;
        if (l == MAX_SIZE)
            l = 0;
        sz--;
    }

    int front()
    {
        if (sz == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return a[l];
    }

    int size()
    {
        return sz;
    }
};
int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    cout << q.size() << endl;

    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << q.size() << endl;
    return 0;
}