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

const int maxn = 2505;
struct BinaryHEAP
{
    int Heap[maxn];
    int sz;
    #define Cmp(a,b) ((a)<(b)) //small
    void push(int x)
    {
        int i = ++sz;
        while(i > 1){
            int p = i>>1;
            if(!Cmp(x,Heap[p])) break;
            Heap[i] = Heap[p];
            i = p;
        }
        Heap[i] = x;
    }

    void pop()
    {
        int x = Heap[sz--];
        int i = 1;
        while((i<<1)<=sz){
            int a = i<<1, b = i<<1|1;
            if(b<=sz && Cmp(Heap[b],Heap[a])) a = b;
            if(!Cmp(Heap[a],x)) break;
            Heap[i] = Heap[a];
            i = a;
        }
        Heap[i] = x;
    }

    int operator[](int x){ return Heap[x]; }
}q;


#define MP make_pair
#define fi first
#define se second

pair<int,int> cow[maxn], lot[maxn];

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int C,L; cin>>C>>L;
    for(int i = 0; i < C; i++){
        scanf("%d%d",&cow[i].fi,&cow[i].se);
    }
    for(int i = 0; i < L; i++){
        scanf("%d%d",&lot[i].fi,&lot[i].se);
    }
    sort(lot,lot+L);
    sort(cow,cow+C);
    int ans = 0;
    for(int i = 0, j = 0; i < L; i++){
        while(j < C && cow[j].fi <= lot[i].fi) {
            q.push(cow[j++].se);
        }
        while(q.sz && q[1] < lot[i].fi ) q.pop();
        while(q.sz && lot[i].se--){
            ans++; q.pop();
        }
    }
    printf("%d\n",ans);
    return 0;
}
