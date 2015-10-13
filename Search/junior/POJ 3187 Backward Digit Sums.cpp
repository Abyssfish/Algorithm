#include<cstdio>
#include<iostream>
#include <iterator>
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

int n,tar;
const int maxn = 11;
int a[maxn];
int C[maxn][maxn];

inline bool ok()
{
    int re = 0;
    for(int i = 0; i < n; i++){
        re += a[i]*C[n-1][i];
    }
    return re == tar;
}

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    for(int i = 0; i < maxn; i++){
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
    scanf("%d%d",&n,&tar);
    for(int i = 0; i < n; i++)a[i] = i+1;
    while(!ok() && next_permutation(a,a+n));
    copy(a, a + n, ostream_iterator<int>(cout, " "));
    return 0;
}
