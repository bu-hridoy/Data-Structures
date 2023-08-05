#include<bits/stdc++.h>
using namespace std;

template <class T>
class Queue
{
public:
    int l,r,sz,arr_cap;
    T *arr;

   Queue() {
    arr = new T[1];
    arr_cap = 1;
    l = 0;
    r = -1;
    sz = 0;
   }
   void remove_circuler()
   {
       if (l > r)
       {
           T *temp = new T[arr_cap];
           int ix = 0;
           for(int i = l; i < arr_cap; i++){
            temp[ix++] = arr[i];
           }

           for(int i = 0; i <= r; i++) {
            temp[ix++] = arr[i];
           }

           swap(temp, arr);
           l = 0;
           r = arr_cap - 1;
           delete temp;
       }
   }
    void increase_size()
    {
        remove_circuler();
        arr_cap = arr_cap * 2;
        T *temp = new T[arr_cap];
        int ix = 0;

        for(int i = l; i < arr_cap; i++){
            temp[i] = arr[i];
        }

        swap(temp, arr);
        delete temp;

    }
    void enqueue(T value)
    {
        if (sz == arr_cap) {
            increase_size();
        }
        sz++;
        r++;
        if (r == arr_cap) {
            r = 0;
        }
        arr[r] = value;
    }

    void dequeue()
    {
        if (sz == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        sz--;
        l++;
        if (l == arr_cap) {
            l = 0;
        }
    }

    T front()
    {
        if (sz == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return arr[l];
    }

    int size()
    {
        return sz;
    }

};

int main()
{
    Queue<double> st;
    st.enqueue(3.66);
    cout << st.front() << endl;
    st.enqueue(4);
    cout << st.front() << endl;
    st.enqueue(5.89);
    cout << st.front() << endl;
    st.dequeue();
    cout << st.front() << endl;
    st.dequeue();
    cout << st.front() << endl;
    st.dequeue();
    st.dequeue();
    return 0;
}

