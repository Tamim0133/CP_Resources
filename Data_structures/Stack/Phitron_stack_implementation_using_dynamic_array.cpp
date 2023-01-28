
#include <bits/stdc++.h>
using namespace std;
int MAX_SIZE = 500;

// Stack Using Static Array
class Stack
{
public:
    int *a;
    int stack_size;
    int cap;

    Stack()
    {
        a = new int[1]; // শুরুতে এক সাইজের একটা এরে নিলাম
        cap = 1;
        stack_size = 0;
    }

    // যদি ক্যাপাসিটী ফিল হয়ে যায় তাহলে আমরা capacity ডাবল করে দিবও
    void increase_size()
    {
        int *tmp; // নতুন Temporary array
        tmp = new int[cap * 2];

        for (int i = 0; i < cap; i++)
            tmp[i] = a[i];

        swap(a, tmp); // নামগুলা অদল বদল হবে
        delete[] tmp;

        cap = cap * 2;
    }

    // এখানে মেইনলি ডাবল সাইজের একটা এরে ডিক্লেয়ার করে তারপরে অই এরেতে আগের এলিমেন্ট গুলা কপি করা হচ্ছে । তারপরে নতুন এরাএর নাম আবার পুরাতন করে , পুরাতনটাকে ডিলিট করা হচ্ছে ।

    // Add a value to the stack O(1)
    void push(int val)
    {
        // যদি এলিমেন্ট এড করার পড়ে আমার এরে এর সাইজ বাইরে চলে যায়
        if (stack_size + 1 > cap)
        {
            increase_size();
        }

        stack_size = stack_size + 1; // Stack সাইজ এক বারাই দিছি
        a[stack_size - 1] = val;     // Index এর পজিশনে ভ্যলু এড করে দিলাম
    }

    // Delete Top most element O(1)
    void pop()
    {
        // যদি stack size শূন্য থাকে তাহলে কিন্তু আর Stack এ pop hobe na
        if (stack_size == 0)
        {
            cout << "Stack is empty !" << endl;
            return;
        }
        // a[stack_size - 1] = 0;
        stack_size = stack_size - 1; // শুধু এইটুকু করলেই চলবে

        // আমরা যখন Stack সাইজ এক কমাই দিবো , তখন আমরা নেক্সট এ জিনিস নিয়ে Concerned না ।
    }
    // Returns the top element from the stack O(1)
    int top()
    {
        if (stack_size == 0)
        {
            cout << "Stack is empty !" << endl;
            return -1;
        }
        return a[stack_size - 1];
    }
};
int main()
{
    Stack st;
    st.push(3);
    cout << st.top() << endl;
    st.push(4);
    cout << st.top() << endl;
    st.push(5);
    cout << st.top() << endl;

    st.pop();
    cout << st.top() << endl;

    return 0;
}