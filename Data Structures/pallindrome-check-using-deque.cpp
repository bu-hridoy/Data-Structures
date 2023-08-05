#include<bits/stdc++.h>
using namespace std;

bool isPallindrome(string S)
{
    deque<char>dq;
    int sz = S.size();
    for(int i = 0; i < sz; i++) {
        dq.push_front(S[i]);
    }

    while(sz > 0) {
        if(dq.front() != dq.back()) {
            return false;
        }
        dq.pop_front();
        sz--;
        if(sz > 0) {
            dq.pop_back();
            sz--;
        }
    }

    return true;
}

int main()
{
    string S;
    cin>>S;

    isPallindrome(S) ? cout<<"Yes" : cout << "No";
    cout <<endl;
}


