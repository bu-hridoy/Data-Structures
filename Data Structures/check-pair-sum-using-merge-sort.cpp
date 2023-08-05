#include<bits/stdc++.h>
using namespace std;
int trg;
bool isPossible = false;

bool pairSum(vector<int>a, vector<int>b)
{
    int n = a.size() + b.size(), ix1 = 0, ix2 = b.size() - 1;
    for(int i = 0 ; i < n; i++) {
        if(ix1 == a.size() || ix2 < 0) {
            break;
        }
        if (a[ix1] + b[ix2] > trg) {
            ix2--;
        } else if (a[ix1] + b[ix2] < trg) {
            ix1++;
        } else {
            return true;
        }
    }

    return false;
}

vector<int>merged(vector<int>a, vector<int>b)
{
    int n = a.size() + b.size(), ix1= 0, ix2 = 0;
    vector<int>v;

    for(int i = 0 ; i < n; i++) {
        if(ix1 == a.size()) {
            v.push_back(b[ix2]);
            ix2++;
        } else if (ix2 == b.size() || a[ix1] < b[ix2]) {
            v.push_back(a[ix1]);
            ix1++;
        } else {
            v.push_back(b[ix2]);
            ix2++;
        }
    }

    return v;
}

vector<int>merge_sort(vector<int>v)
{
    int n = v.size();
    vector<int>a,b;

    if (n <= 1) return v;

    for(int i = 0 ; i < n/2; i++)
        a.push_back(v[i]);

    for(int i = n/2; i < n; i++)
        b.push_back(v[i]);

    vector<int>sorted_a = merge_sort(a);
    vector<int>sorted_b = merge_sort(b);

    isPossible = isPossible | pairSum(sorted_a, sorted_b);

    return merged(sorted_a, sorted_b);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0 ; i < n; i++)
        cin>>v[i];

    cin>>trg;
    vector<int>ans = merge_sort(v);

    isPossible ? cout<< "YES" : cout << "NO";
    cout << endl;
}

