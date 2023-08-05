#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>PAIR;

vector<PAIR>VECTOR;
int Dis[100],Cost[1000][1000];

void init()
{
    for(int i=0; i<=100; i++)
        Dis[i] = INT_MAX;
}

bool Bellman_Ford(int Node, int Source_Node)
{
    Dis[Source_Node]=0;

    for(int i=1; i<Node; i++)
    {
        for(int j=0; j<VECTOR.size(); j++)
        {
            int U=VECTOR[j].first;
            int V=VECTOR[j].second;
            if(Dis[U]+Cost[U][V]<Dis[V])
                Dis[V]=Dis[U]+Cost[U][V];
        }
    }

    for(int j=0; j<VECTOR.size(); j++)
    {
        int U=VECTOR[j].first;
            int V=VECTOR[j].second;
            if(Dis[U]+Cost[U][V]<Dis[V])
                return false;
    }
    return true ;
}
int main()
{
    int Node,Edge,X,Y,W;
    cin>>Node>>Edge;

    for(int i=1; i<=Edge; i++)
    {
        cin>>X>>Y>>W;
        VECTOR.push_back(make_pair(X,Y));
        Cost[X][Y]=W;
    }
    init();
    int Source_Node;
    cin>>Source_Node;
    bool Flag=Bellman_Ford(Node, Source_Node);

    if(!Flag)
    {
        cout<<"Negative cycle"<<endl;
    }
    else
    {
        for(int i=1; i<=Node; i++)
        {
            cout<<"Sortest path From "<<Source_Node<<" To Node "<<i<<" --> "<<Dis[i]<<endl;
        }
    }
}
