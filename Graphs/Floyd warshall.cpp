#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
long long int d[MAX][MAX];

int init(int node)
{
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
            d[i][j]=INT_MAX;
    }
}

void floyd(int node)
{
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
           if(i==j)
                d[i][j]=0;
    }

    for(int k=1; k<=node; k++ )
    {
        for(int i=1; i<=node; i++)
        {
            for(int j=1; j<=node; j++)
            {
               if(d[i][j]>d[i][k]+d[k][j])
                 d[i][j]=d[i][k]+d[k][j];
            }
        }
    }
}
int main()
{
    int node,edge,X,Y,dis;
    cin>>node>>edge;
    init(node);

    for(int i=1; i<=edge; i++)
    {
        cin>>X>>Y>>dis;
        d[X][Y]=dis;
    }


    floyd(node);

        for(int i=1; i<=node; i++)
        {
            for(int j=1; j<=node; j++)
            {
                    cout<<"Node "<<i <<" to Node "<<j<<" distance --> "<<d[i][j]<<endl;
            }
        }
    return 0;
}
