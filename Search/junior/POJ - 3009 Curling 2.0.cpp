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


const int maxn = 25;
int g[maxn][maxn];
int W,H;
int ans;

const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

bool inside(int x,int y)
{
    return x>=0&&x<H&&y>=0&&y<W;
}

void dfs(int x,int y,int d)
{
    if(d+1 >= ans) { return ; }
    for(int k = 0; k < 4;k++){
        int nx = x+dx[k], ny = y+dy[k];
        if(inside(nx,ny) && g[nx][ny] != 1){
            while(inside(nx,ny) && g[nx][ny] == 0) nx += dx[k], ny += dy[k];
            if(inside(nx,ny)){
                if(g[nx][ny] == 3){  ans = d+1; continue; }
                g[nx][ny] = 0;
                dfs(nx-dx[k],ny-dy[k],d+1);
                g[nx][ny] = 1;
            }
        }
    }
}

int sol()
{
    int sx,sy,tx,ty;
    REP0(i,H){
        REP0(j,W){
            if(g[i][j] == 2){
                sx = i; sy = j;
                ans = 11;//min(11,abs(sx-tx)+abs(sy-ty));
                g[sx][sy] = 0;
                dfs(sx,sy,0);
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
    while(scanf("%d%d",&W,&H),W){
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                scanf("%d",g[i]+j);
            }
        }
        int ans = sol();
        printf("%d\n",ans < 11?ans:-1);
    }
    return 0;
}
//freopen("OutStd.txt","w",stdout);
