#include<bits/stdc++.h>
using namespace std;

inline int read()
{
    int ret; char c; while(c = getchar(),c<'0'||c>'9');
    ret = c-'0';
    while(c = getchar(),c>='0'&&c<='9') ret = ret*10 + c-'0';
    return ret;
}

int reads()
{
    int ret; char c; while(c = getchar(),c != '-' && c<'0'||c>'9');
    bool Sign = c == '-';
    ret = Sign?0:c-'0';
    while(c = getchar(),c>='0'&&c<='9') ret = ret*10 + c-'0';
    return Sign?-ret:ret;
}

int a[11];

bool dfs(int i = 0,int lsl = -1,int lsr = -1)
{
    if(i == 10) return true;
    return ( (!~lsl || a[i] > a[lsl]) && dfs(i+1,i,lsr) )||( (!~lsr || a[i] > a[lsr]) && dfs(i+1,lsl,i) );
}

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int T = read();
    while(T--){
        for(int i = 0; i < 10; i++) a[i] = read();
        puts(dfs()?"YES":"NO");
    }
    return 0;
}
