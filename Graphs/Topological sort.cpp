#include<bits/stdc++.h>
using namespace std;
int node,edge,X,Y,indegree[100];
vector<int>List;
vector<int>V[100];
queue<int>Q;

void topsort()
{
    for(int i=1; i<=node; i++)
    {
        if(indegree[i]==0){
            Q.push(i);
            List.push_back(i);
        }
    }
    int u,sz;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        sz=V[u].size();

        for(int i=0; i<sz; i++)
        {
            indegree[V[u][i]]--;
            if(indegree[V[u][i]]==0){
                Q.push(V[u][i]);
                  List.push_back(V[u][i]);
            }
        }
    }
}

int main()
{
    cin>>node>>edge;
    for(int i=1; i<=edge; i++)
    {
        cin>>X>>Y;
        V[X].push_back(Y);
        indegree[Y]++;
    }
    topsort();

    for(int i=0; i<List.size(); i++)
        cout<<i+1<<"-->"<<List[i]<<endl;
}
