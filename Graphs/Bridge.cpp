#include<bits/stdc++.h>
using namespace std;

#define     II(X, Y)        scanf("%d%d",&(X),&(Y))
#define     pb              push_back

vector<int>V[100005];
int visited[100005],T;
int low[100005],dis[100005],par[100005];

void AP(int u)
{
   dis[u]=low[u]=T++;
    visited[u]=1;
    for(int i=0;i<V[u].size();i++)
    {
        int v=V[u][i];
        if(visited[v]==0)
        {
            par[v]=u;
            AP(v);

            low[u]=min(low[u],low[v]);

            if(dis[u] < low[v])
              cout<<v<<"--"<<u<<endl;

        }
        if(par[u]!=v)
            low[u]=min(low[u],dis[v]);

    }
}

int main()
{
    int n,m;
    II(n,m);

    memset(par,-1,sizeof par);

    for(int i=0; i<m; i++)
    {
        int x,y;
        II(x,y);
        V[x].pb(y);
        V[y].pb(x);
    }

    for(int i=1; i<=n; i++){
            T=0;
     if(visited[i]==0)
        AP(i);
    }
}

