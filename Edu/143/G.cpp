#include<bits/stdc++.h>
#define ull unsigned long long
//#define std
using namespace std;
const int nn=1e5+5;
int T,N,M;
int A[nn],D[nn];
vector<int>G[nn];
int Sta[nn];
vector<ull> s(N+1);
vector<pair<int,int> >g2;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++){
            D[i]=0;
            G[i].clear();
            scanf("%d",&A[i]);
        }
        for(int x,y,i=1;i<=M;i++){
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
            D[x]++; D[y]++;
        }
        int hd=0;
        for(int i=1;i<=N;i++)
        if(D[i]==A[i]){
            Sta[++hd]=i;
        }
        
        while(hd){
            int u=Sta[hd--];
            for(int v:G[u]){
                D[v]--;
                g2.push_back({u,v});
                if(D[v]==A[v]){
                    Sta[++hd]=v;
                }
            }
        }
        reverse(g2.begin(),g2.end());
        long long ans=0;
#ifdef std
        
        for(int l=1;l<=N;l+=64){
            int r=min(N,l+64-1);
            for(int i=l;i<=r;i++) s[i]=1ull << (i-l);
            for(auto it:g2) s[it.first]|=s[it.second];
            for(int i=1;i<=N;i++) 
             ans+=__builtin_popcountll(s[i]),s[i]=0;
        }
#endif
#ifndef std
        int f[N+1];
        for(int i=1;i<=N;i++) f[i]=0;
        for(auto it:g2){
            f[it.first]+=f[it.second]+1;
        }
        for(int i=1;i<=N;i++) ans+=f[i];
#endif
        ans=1ll*N*(N-1)/2-ans;
        printf("%lld\n",ans);
    }
    return 0;
}