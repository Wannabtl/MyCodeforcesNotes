#include<bits/stdc++.h>
//#define debug
using namespace std;
#ifdef debug
const int nn=10;
#endif
#ifndef debug
const int nn=2e5+5;
#endif
int T,N,K;
int A[nn];
vector<int>E[nn];
int Nd[nn],Ca[nn];
bool Dfs(int u,int p){
    for(int v:E[u]){
        if(v==p) continue ;
        if(!Dfs(v,u)) return 0; //如果有节点不可行则return
        if(!Nd[v]) Ca[u]=max(Ca[u],Ca[v]+1); //判断最长可行路径,只有子节点不在路当上当
    }
    if(!Nd[u]||Ca[u]>=Nd[u]) return 1; //如果该节点没有需求，或者存在向下路径满足需求
    if(Nd[p]||!p) return 0; //如果祖先已经有别的需求或者没有祖先
    Nd[p]=Nd[u]-1;
    return 1;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++) E[i].clear();
        for(int x,y,i=1;i<N;i++){
            scanf("%d%d",&x,&y);
            E[x].push_back(y);
            E[y].push_back(x);
        }
        scanf("%d",&K);
        for(int i=1;i<=K;i++)
         scanf("%d",&A[i]);
        int l=0,r=N;
        while(l<r){
            int mid=l+r+1>>1;
            //printf("%d %d\n",l,r);
            for(int i=1;i<=N;i++)
             Nd[i]=0,Ca[i]=1; 
            for(int i=1;i<=K;i++)
             Nd[A[i]]=mid/K+(mid%K>=i)+1; //计算碎片的需求路径长度,碎片初始为1因为自身是黑色
            if(Dfs(1,0)) l=mid;
            else r=mid-1;       
        }
        printf("%d\n",l);
    }
    return 0;
}