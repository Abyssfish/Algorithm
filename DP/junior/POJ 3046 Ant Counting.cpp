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
//#include<bits/stdc++.h>
using namespace std;

int T, A, S, B;
const int maxt = 1e3+5, maxa = 1e5+5, mod = 1e6;
int f[2][maxa];
int c[maxt];

//f[i][j] = sigma{(k = 0,min(j,c[i])) f[i-1][j-k]  }
//i,j   j-0,j-1,...,j-a[i]
//i,j-1     j-1,j-2,...,j-a[i]-1


//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    scanf("%d%d%d%d",&T,&A,&S,&B);
    for(int i = A; i--;){
        int x; scanf("%d",&x);
        c[x]++;
    }
    f[0][0] = f[1][0] = 1;
    for(int i = 1; i <= T; i++){
        int a = i&1, b = a^1;
        for(int j = 1; j <= B; j++){
            if(j-c[i]>0){
                f[a][j] = ( f[a][j-1] + f[b][j] - f[b][j-1-c[i]] ) % mod;
            }else {
                f[a][j] = ( f[a][j-1] + f[b][j] ) % mod;
            }
        }
    }
    int sum = 0, *F = f[T&1];
    for(int i = S; i <= B; i++){
        sum = (sum + F[i]) % mod;
    }
    printf("%d\n",sum<0?sum+mod:sum);
    return 0;
}
