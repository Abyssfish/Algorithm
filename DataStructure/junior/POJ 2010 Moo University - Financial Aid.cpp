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

#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define PS push

const int maxn = 1e5+5;
const int maxsz = 1e4+5;
struct BinaryHEAP
{
    int Heap[maxsz];
    int sz;
    #define Cmp(a,b) ((a)>(b))
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
    int top(){ return Heap[1]; }
    //int operator[](int x){ return Heap[x]; }
}q;

pair<int,int> cow[maxn];
int N, C, F;
int Half;
int preSum[maxn];


int sol()
{
    sort(cow,cow+C);
    int Half = N>>1, sum = 0;
    for(int i = 0; i < Half; i++) {
        sum += cow[i].se;
        q.push(cow[i].se);
    }
    for(int i = Half; i < C-Half; i++){
        preSum[i] = sum;
        if(q.top() > cow[i].se) {
            sum -= q.top();
            q.pop();
            sum += cow[i].se;
            q.push(cow[i].se);
        }

    }
    q.sz = 0;
    sum = 0;
    for(int i = C-Half; i < C; i++) {
        sum += cow[i].se;
        q.push(cow[i].se);
    }
    for(int i = C-Half; --i >= Half; ){
        if(sum + preSum[i] + cow[i].se <= F) return cow[i].fi;
        if(q.top() > cow[i].se) {
            sum -= q.top();
            q.pop();
            sum += cow[i].se;
            q.push(cow[i].se);
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

    scanf("%d%d%d",&N,&C,&F);
    for(int i = 0; i < C; i++){
        scanf("%d%d",&cow[i].fi,&cow[i].se);
    }
    printf("%d\n",sol());
    return 0;
}
