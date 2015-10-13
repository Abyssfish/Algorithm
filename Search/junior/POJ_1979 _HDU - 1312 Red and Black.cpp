#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define PS push

#define cer(x) cout<<#x<<'='<<endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
//const int mINF = -1-INF;//0xc0c0c0c0;
#define REP0(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define DWN(i,n) for(int i = n; i > 0; i--)
#define DWN_(i,n) for(int i = n; i >= 0; i--)
#define REP(i,s,e) for(int i = s; i < e; i++)
#define REP_(i,s,e) for(int i = s; i <= e; i++)
#define CLR(a,v) memset(a,v,sizeof(a))

#define para int o = 1, int l = 1,int r = n
#define lo (o<<1)
#define ro (o<<1|1)
#define TEMP int mid = (l+r)>>1;
#define lsn lo, l, mid
#define rsn ro, mid+1, r
#define insd ql<=l&&r<=qr

const int maxn = 21;
char maz[maxn][maxn];
int vis[maxn][maxn],clk;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int W,H;
bool chk(int x,int y)
{
    return x>=0&&x<H&&y>=0&&y<W&&maz[x][y]=='.'&&vis[x][y]!=clk;
}

int ans;
void dfs(int x,int y)
{
    ans++;
    for(int i = 0; i < 4; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(chk(nx,ny)){
            vis[nx][ny] = clk;
            dfs(nx,ny);
        }
    }
}

int sol()
{
    clk++; ans = 0;
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W; j++){
            if(maz[i][j] == '@'){
                dfs(i,j);
                return ans;
            }
        }
    }
}

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif

    while(scanf("%d%d",&W,&H),W+H){
        for(int i = 0; i < H;i++){
            scanf("%s",maz[i]);
        }
        printf("%d\n",sol());
    }
    return 0;
}
//freopen("OutStd.txt","w",stdout);
