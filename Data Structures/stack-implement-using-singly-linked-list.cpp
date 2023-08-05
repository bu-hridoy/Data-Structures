#include<bits/stdc++.h>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node * nxt;
};

template <class T>
class SinglyLinkedList
{
public:
    node<T> * head;
    int sz;
    SinglyLinkedList()
    {
        head = NULL;
        sz=0;
    }

    //Creates a new node with data = value and nxt= NULL
    node<T> *CreateNewNode(T value)
    {
        node<T> *newnode = new node<T>;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    // Insert new value at Head
    void InsertAtHead(T value)
    {
        sz++;
        node<T> *a = CreateNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        //If head is not NULL
        a->nxt = head;
        head = a;
    }

    //Delete the first element of a linked list
    void DeleteAtHead()
    {
        if(head == NULL)
        {
            return;
        }
        sz--;
        node<T> *a = head;
        head = a->nxt;
        delete a;
    }

    //Returns number of elements in the linked list
    int getSize()
    {
        return sz;
    }

};
template <class T>
class Stack {
public:
    SinglyLinkedList<T> sl;

    Stack()
    {

    }

    T top()
    {
        if(sl.getSize() == 0) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return sl.head->data;
    }

    void push(T val)
    {
        sl.InsertAtHead(val);
    }
    void pop()
    {
        if(sl.getSize() == 0) {
            cout << "Stack is Empty" << endl;
            return;
        }

        sl.DeleteAtHead();
    }

};

int main()
{
    Stack<double> st;
    st.push(3.66);
    cout << st.top() << endl;
    st.push(4);
    cout << st.top() << endl;
    st.push(5.89);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    st.pop();
    return 0;
}

