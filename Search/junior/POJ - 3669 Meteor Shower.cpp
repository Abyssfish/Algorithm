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

inline int read()
{
    int ret; char c; while(c = getchar(),c<'0'||c>'9');
    ret = c-'0';
    while(c = getchar(),c>='0'&&c<='9') ret = ret*10 + c-'0';
    return ret;
}

inline int reads()
{
    int ret; char c; while(c = getchar(),c != '-' && c<'0'||c>'9');
    bool Sign = c == '-';
    ret = Sign?0:c-'0';
    while(c = getchar(),c>='0'&&c<='9') ret = ret*10 + c-'0';
    return Sign?-ret:ret;
}

const int maxn = 305;
int g[maxn][maxn];
int d[maxn][maxn];
const int MxT = 1001;
typedef pair<int,int> Node;

const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
bool valid(int x,int y)
{
    return x>=0&&x<maxn&&y>=0&&y<maxn;
}
int bfs()
{
    queue<Node>q;
    q.push(Node(0,0));  d[0][0] = 1;
    while(q.size()){
        Node u = q.front(); q.pop();
        if(g[u.fi][u.se] > MxT) return d[u.fi][u.se]-1;
        int step = d[u.fi][u.se];
        for(int k = 0; k < 4; k++){
            int nx = u.fi+dx[k], ny = u.se+dy[k];
            if(valid(nx,ny) &&!d[nx][ny] && step < g[nx][ny]){
                d[nx][ny] = step+1;
                q.push(Node(nx,ny));
            }
        }
    }
    return -1;
}

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int M = read();
    memset(g,0x3f,sizeof(g));
    for(int i = M; i--;){
        int x = read(), y = read();
        int t = read();
        for(int k = 0; k < 4; k++){
            int nx = x+dx[k], ny = y+dy[k];
            if(valid(nx,ny)){
                g[nx][ny] = min(g[nx][ny],t);
            }
        }
        g[x][y] = min(g[x][y],t);
    }
    printf("%d\n",bfs());
    return 0;
}
//freopen("OutStd.txt","w",stdout);
