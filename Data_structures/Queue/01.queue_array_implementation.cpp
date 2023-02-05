#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 500;

class Queue
{
public:
    int a[MAX_SIZE];
    int l, r;
    Queue()
    {
        l = 0;
        r = -1;
    }
    // এল সমান ০ করা হয়েছে কারন শুরু সবসময় ওখানেই থাকবে । আবার আর এর মান -১ করা হয়েছে । এতে করে আর মাইনাস এল যেটা সাইজ নির্দেশ করে , যেহেতু এল > আর তাই সাইজ জিরো হবে ।
    // পড়ে যখন একটা এলিমেন্ট এড করা হবে তখন আর এর মান বাড়ানো হবে কিন্তু এল এর মান এক ই থাকবে ।

    void enqueue(int value) // O(1)
    {
        if (r + 1 >= MAX_SIZE)
        {
            cout << "Queue is full" << endl;
            return;
        }
        r++;
        a[r] = value;
    }

    void dequeue() // O(1)
    {
        if (l > r)
        {
            cout << "Queue is full " << endl;
            return;
        }
        l++;
    }

    int front()
    {
        if (l > r)
        {
            cout << "Queue is full" << endl;
            return -1;
        }
        return a[l];
    }

    int size()
    {
        return r - l + 1;
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