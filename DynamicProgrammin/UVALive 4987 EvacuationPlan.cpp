#include<bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for(int i = s; i <= e; i++)

const int maxn = 4e3+5;
typedef long long ll;
struct Node
{
    int d, id;
    bool operator < (const Node& th) const{
        return d < th.d;
    }
}a[maxn], b[maxn];//teams, shelters

int ans[maxn];

ll dp[maxn];

bool path[maxn][maxn];
#define cost(i,j) abs(a[i].d-b[j].d)

#define READ(a,n)\
REP(i,1,n) scanf("%d",&a[i].d),a[i].id = i;\
sort(a+1,a+n+1);

int n, m;
void Print_ans()
{
    printf("%lld\n",dp[m]);
    int i = n+1, j = m;
    while(--i){
        ans[a[i].id] = path[i][j]?j:j--;
    }
    while(++i<=n){
        printf("%d%c",b[ans[i]].id,i==n?'\n':' ');
    }
}

int main()
{
    while(~scanf("%d",&n)){
        READ(a,n)
        scanf("%d",&m);
        READ(b,m)
        memset(dp,0x3f,sizeof(ll)*(m+1));
        dp[1] = cost(1,1); //第1个team选1号shelter
        REP(i,2,n){
            for(int j = min(m,i); j > 0; j--){
                int pj = (dp[j] < dp[j-1])?j:j-1;
                path[i][j] = pj == j;
                dp[j] = dp[pj] + cost(i,j);
            }
        }
        Print_ans();
    }
    return 0;
}

