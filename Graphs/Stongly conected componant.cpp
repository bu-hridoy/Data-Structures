#include<bits/stdc++.h>
using namespace std;
stack<int>S;
bool Visited [1000];
vector<int>V1[1000],V2[1000],Component[1000];
int Compo=0,node;

void Fill_Stact(int u)
{
    Visited[u]=true;
    int sz=V1[u].size();

    for(int i=0; i<sz; i++)
    {
        int v=V1[u][i];
        if(Visited[v]==false)
            Fill_Stact(v);
    }

    S.push(u);
}

void DFS(int u,int index)
{
    Component[index].push_back(u);
    Visited[u]=true;
    int sz=V2[u].size();

    for(int i=0; i<sz; i++)
    {
        int v=V2[u][i];
        if(Visited[v]==false)
            DFS(v,index);
    }
}

void SCC()
{
    for(int i=0; i<node; i++)
        Visited[i]=false;

    while(!S.empty())
    {
        int u=S.top();
        S.pop();

        if(Visited[u]==false){
            DFS(u,Compo);
            Compo++;
        }
    }
}

int main()
{
    int edge;
    cin>>node>>edge;

    for(int i=0; i<edge; i++){
        int x,y;
        cin>>x>>y;
        V1[x].push_back(y);
        V2[y].push_back(x);
    }


    for(int i=0; i<node; i++)
    {
        if(Visited[i]==false){
            Fill_Stact(i);
        }
    }

    SCC();

    cout<<endl<<Compo<<endl;

    for(int i=0; i<Compo; i++)
    {
        int siz=Component[i].size();
        for(int j=0; j<siz; j++)
            cout<<Component[i][j]<<" ";
        cout<<endl;
    }
}
