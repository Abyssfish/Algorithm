#include<bits/stdc++.h>
using namespace std;

#define PS push
#define PB push_back
#define MP make_pair
#define fi first
#define se second
const int INF = 0x3f3f3f3f;

typedef long long ll;

inline int read()
{
    int ret; char c; while(c = getchar(),c<'0'||c>'9');
    ret = c-'0';
    while(c = getchar(),c>='0'&&c<='9') ret = ret*10 + c-'0';
    return ret;
}

const int SZ = 1e3+5;

char g[SZ][SZ];
int H,W,N;
int vis[SZ][SZ],clk;
struct Node
{
    int x,y,f,h;
    bool operator <(const Node&th) const {
        return f > th.f || ( f == th.f && h < th.h);
    }
}pos[10];

int tar;
inline int MHT(Node &o)
{
    return (abs(pos[tar].x-o.x) + abs(pos[tar].y-o.y));//>>1
}

void GetPos()
{
    REP0(i,H){
        REP0(j,W){
            char c = g[i][j];
            if(c == 'S'){
                pos[0] = {i,j};
            }else if('1'<= c && c <='9' ){
                pos[c-'0'] = {i,j};
            }
        }
    }
}

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

inline bool valid(int x,int y)
{
    return x>=0&&x<H&&y>=0&&y<W&&g[x][y]!='X'&&vis[x][y] != clk;
}

int astar_bfs(int st)
{
    priority_queue<Node> q;
    Node u;
    u.x = pos[st].x;
    u.y = pos[st].y;
    u.h = u.f = MHT(u);
    q.push(u);
    clk++;
    while(q.size()){
        u = q.top(); q.pop();
        if(u.x == pos[tar].x && u.y == pos[tar].y ) return u.f-u.h;
        REP0(k,4){
            Node v;
            v.x = u.x + dx[k];
            v.y = u.y + dy[k];
            if(!valid(v.x,v.y)) continue;
            vis[v.x][v.y] = clk;
            v.h = MHT(v);
            v.f = u.f-u.h+1+v.h;
            q.push(v);
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
    H = read(); W = read(); N = read();
    for(int i = 0; i < H; i++){
        scanf("%s",g[i]);
    }
    GetPos();
    int ans = 0;
    REP1(i,N){
        tar = i;
        ans += astar_bfs(i-1);
    }
    printf("%d\n",ans);
    return 0;
}
