#include<bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
template <typename T> using orderset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
orderset <int> myset;
ordered_set mymultiset;
int t = 0;
int main()
{
    int n;
    cin>>n;

    for(int i = 0 ; i < n; i++){
        int x;
        cin>>x;
        myset.insert(x);
        mymultiset.insert({x, t++});
    }

    ///SET
    int a;
    cin>>a;
    int under_kth = myset.order_of_key(a);
    cout<<"Total numbers strictly less than "<<a<<" is " << under_kth<<endl;
    int k;
    cin>>k;
    int kth = *myset.find_by_order(k - 1);
    cout<<"The "<<k<<"'th element in the set is " <<kth<<endl; /// Index 1 base
    myset.erase(kth);
    kth = *myset.find_by_order(k - 1);
    cout<<"Next "<<k<<"'th element after erase previous k'th element "<<kth<<endl;


    ///MultiSET
    cin>>a;
    int tot = mymultiset.order_of_key({a,t+2});
    cout<<"Total Numbers strictly less than or equal to "<<a<<" is "<<tot<<endl;
    cin>>k;
    kth = mymultiset.find_by_order(k - 1)->first;
    cout<<"The "<<k<<"'th element in the multiset is " <<kth<<endl; /// Index 1 base
    mymultiset.erase(mymultiset.lower_bound({kth,2}));
    kth = mymultiset.find_by_order(k)->first;
    cout<<"Next "<<k<<"'th element after erase previous k'th element "<<kth<<endl;

}
