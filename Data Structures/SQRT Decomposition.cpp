#include<bits/stdc++.h>
using namespace std;

/*-------------------------- HRIDOY ROY -------------------------*/

#define     fRead           freopen("input.txt","r",stdin)
#define     fWrite          freopen("output.txt","w",stdout)

#define     I(X)            scanf("%d",&(X))
#define     II(X, Y)        scanf("%d%d",&(X),&(Y))
#define     III(X,Y,Z)      scanf("%d%d%d",&(X),&(Y),&(Z))
#define     IL(X)           scanf("%lld",&(X))
#define     IIL(X, Y)       scanf("%lld%lld",&(X),&(Y))
#define     pb              push_back
#define     popb            pop_back
#define     lld             long long int
#define     ull             unsigned long long int
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(max3(a,b,c),d)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(a,min3(b,c,d))
#define     MOD             1000000007
#define     f               first
#define     s               second
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     mp              make_pair

#define     show            printf("---***---")
#define     all(v)          v.begin(),v.end()
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     pii             pair<int,int>
#define     PLL             pair<lld,lld>
#define     MAX             100000000000014
#define     MIN             -100000000000014
#define     gti             greater<int>
#define     gtL             greater<lld>
#define     PI1             acos(-1.0)
#define     pi2             2.0*acos(0.0)
#define     endl            '\n'

//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
//__builtin_popcount // back_inserter() // stoll
// priority_queue<pii,vector<pii>,greater<pii> >q;
//priority_queue<string,vector<pair<string,int>>,greater<pair<string,int>> >q;
//priority_queue<int, vector<int>, greater<int> >pq; // DSCS;
//priority_queue<int, vector<int>, less<int> >pq; // INCS;

int Day12[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int prime100[]={2, 3, 5, 7, 11, 13, 17, 19, 23,29,31, 37, 41, 43, 47, 53, 59,61, 67,71, 73, 79, 83, 89, 97, 101, 103 };
//unsigned long long int phi[5000005]; // count relatively prime for 1 to n//
//void MYFHI(){lld max = 5000001;for(lld i=2;i<max;i++){ if(phi[i]==0){ phi[i]=i-1;for(lld j=i*2;j<max;j=j+i){ if(phi[j]==0) phi[j]=j;phi[j]=phi[j]-(phi[j]/i);}}}}
template <typename T> inline bool isLeap(T y) {return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false);}
template <typename T> inline T GCD (T a,T b ) {a = abs(a);b = abs(b); if(a < b) swap(a, b); while ( b ) { a = a % b; swap ( a, b ); } return a;}
template <typename T> inline T LCM(T x,T y){T tp = GCD(x,y);if( (x / tp) * 1. * y > 9e18) return 9e18;return (x / tp) * y;}
template <typename T> inline T BIGMOD(T A,T B,T M = MOD){T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}
template <typename T> inline T BigMod(T A,T B,T M){T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}
lld MySqrt(lld n){lld p=sqrt(n);if((p+1)*(p+1)<=n) return p+1;else if(p*p<=n) return p;else return p-1;}
lld MyPow(lld x, lld n){if(n==0) return 1; else if(n%2==0) return MyPow(x*x,n/2); else return x*MyPow(x*x,((n-1)/2));}
lld modInverse(lld n){ return BIGMOD(n,(lld)MOD-2)%MOD;}

//----------------------------- O.D.Y.W.F.M ----------------------------------//
const int sz=100005;
const int inf=(1<<28);
template<typename t> t MIN3(t a,t b, t c){return min(a,min(b,c));}
int BLOCK[400];
int arr[sz];
int getId(int indx,int blockSZ)
{
    return indx/blockSZ;
}
void init(int sz)
{
    for(int i=0; i<=sz; i++)
        BLOCK[i]=inf;
}
void update(int val,int indx,int blockSZ)
{
    int id=getId(indx,blockSZ);
    BLOCK[id]=min(BLOCK[id],val);
}
int query(int L,int R,int blockSZ)
{
    int lid=getId(L,blockSZ);
    int rid=getId(R,blockSZ);
    if(lid==rid)
    {
        int ret=inf;
        for(int i=L; i<=R; i++)
            ret=min(ret,arr[i]);
        return ret;
    }
    int m1=inf,m2=inf,m3=inf;
    for(int i=L; i<(lid+1)*blockSZ; i++)m1=min(m1,arr[i]);
    for(int i=lid+1;i<rid;i++)m2=min(m2,BLOCK[i]);
    for(int i=rid*blockSZ; i<=R; i++)m3=min(m3,arr[i]);
    return MIN3(m1,m2,m3);
}
int main()
{
    int N,Q;
    scanf("%d %d",&N,&Q);
    int blockSZ=sqrt(N);
    init(blockSZ);
    for(int i=0; i<N; i++)
    {
        int x;
        scanf("%d",&x);
        arr[i]=x;
        update(x,i,blockSZ);
    }
    while(Q--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",query(x,y,blockSZ));
    }
    return 0;
}
