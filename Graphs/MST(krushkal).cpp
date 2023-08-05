#include<bits/stdc++.h>
using namespace std;
int Node,edge,X,Y,W;
typedef pair<int, pair<int,int>>PAIR;

vector<PAIR>E;

int Par[100];

void init(int N)
{
    for(int i=1; i<=N; i++)
        Par[i]=i;
}

int Find(int A)
{
    if(Par[A]==A) return A;

    Par[A]=Find(Par[A]);
    return Par[A];

}

int krushkal()
{
    sort(E.begin(),E.end());
    int Siz=E.size();
    int M,N,ans=0,flag=0;

    for(int i=0; i<Siz; i++){
    M=Find(E[i].second.first);
    N=Find(E[i].second.second);

    if(M!=N)
    {
        Par[M]=N;
        ans+=E[i].first;
        flag++;
    }

    if(flag==Node-1) break ;
    }

    return ans;
}
int main()
{

    cin>>Node>>edge;
    init(Node);

    for(int i=1; i<=edge; i++)
    {
        cin>>X>>Y>>W;
        E.push_back(make_pair(W,make_pair(X,Y)));
    }

    cout<<krushkal()<<endl;
}
