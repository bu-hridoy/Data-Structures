#include<bits/stdc++.h>
using namespace std;
vector<int>V[1000];
int visited[1000],Ap[1000],Time=0;
int low[1000],par[1000],dis[1000];

void AP(int u)
{
    dis[u]=low[u]=Time++;
    int child=0;
    visited[u]=1;
    int sz=V[u].size();

    for(int i=0; i<sz; i++)
    {
        int v=V[u][i];
        if(visited[v]==0)
        {
            child++;
            par[v]=u;
            AP(v);

            low[u]=min(low[v],low[u]);

            if(par[u]==-1 && child>1)
                Ap[u]=1;
            if(par[u]!=-1 && dis[u]<=low[v])
                Ap[u]=1;

        }
        else if(v!=par[u])
            low[u]=min(dis[v],low[u]);

    }
}

int main()
{
    int node;
    scanf("%d",&node);
    for(int i=0; i<node+5; i++)
    {
        par[i]=-1;
        Ap[i]=0;
    }

    int E;
    scanf("%d",&E);
    for(int i=0; i<E; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);

        V[x].push_back(y);
        V[y].push_back(x);
    }

    for(int i=0; i<node; i++)
    {
        if(visited[i]==0)
            AP(i);
    }

    for(int i=0; i<node; i++)
    {
        if(Ap[i]==1)
            cout<<i<<"  ";
    }
}
