#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

long long int n,m,u,v,w,i,d[1000000];
vector<pii>G[1000000];
priority_queue<pii,vector<pii>,greater<pii> >q;
vector<int>print;
int main()
{

    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v>>w;
        G[u].push_back(pii(w,v));
        G[v].push_back(pii(w,u));
    }

    for(i=1;i<=n;i++)
    {
        d[i]=999999999999999;
    }

    int s;
    cin>>s;

    q.push(pii(0,s));
    d[s]=0;

    while(!q.empty())
    {
        u=q.top().second;
        q.pop();

        for(i=0;i<(int)G[u].size();i++)
        {23
            v=G[u][i].second;
            w=G[u][i].first;
            if(d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                q.push(pii(w,v));
            }
        }

    }

    for(int i=1; i<=n; i++)
    {
         if(i!=s)
         {
             if(d[i]!=999999999999999) cout<<d[i]<<" ";
             else cout<<"-1 ";
         }
    }
    cout<<endl;

}

