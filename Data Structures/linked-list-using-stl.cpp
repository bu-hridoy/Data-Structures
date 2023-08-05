#include<bits/stdc++.h>
using namespace std;

void Print(list<int>&l)
{
    for(auto i : l) {
        cout << i << " ";
    }
    cout << endl;
}

int getIndex(list<int>&l, int val)
{
    int index = 0;
    for(auto i : l) {
       if(i == val) {
        return index;
       }
       index++;
    }
    return -1;
}

void Erase(list<int>&l, int val)
{
    int ix = getIndex(l, val);
    if(ix == -1) cout << val << " not found" << endl;
    else {
        auto it = l.begin();
        advance(it, ix);
        l.erase(it);
    }
}

int main()
{
    list<int>l;
    l.push_back(7);
    l.push_back(3);
    l.push_back(8);
    l.push_back(4);
    l.push_back(5);
    l.push_back(4);

    Print(l);
    int trg;
    cin>>trg;

    Erase(l,trg);
    Print(l);
}

