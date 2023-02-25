# [A. Two Towers]([Problem - A - Codeforces](https://codeforces.com/contest/1795/problem/A))
## Def
> 给出长为n,m的两个01栈，可以将栈顶的元素移往另一个栈顶，问是否可以使得两个栈中元素均为01交替
## Sol
> 因为是栈顶，可以知道操作等价于由一边单向向另一边移动，顺着两个方向跑两次判断可行性即可
## Code
```cpp
#include<bits/stdc++.h>
using namespace std;
bool cmp(char *s1,int n,char *s2,int m){
    int fl=1,k=-1;
    for(int i=2;i<=n;i++)
    if(s1[i]==s1[i-1]){
        k=i;
        break ;
    }
    for(int i=2;i<=m;i++)
    if(s2[i]==s2[i-1]) return 0;
    if(k==-1) return 1;
    char c=s2[m];
    for(int i=n;i>=k;i--){
        if(s1[i]==c) return 0;
        c=s1[i];
    }
    return 1;
}
int main(){
    int t,n,m;
    cin>>t;
    char s1[21],s2[21];
    while(t--){
        cin>>n>>m;
        cin>>s1+1>>s2+1;
        if(cmp(s1,n,s2,m)||cmp(s2,m,s1,n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
```
# [B. Ideal Point]([Problem - B - Codeforces](https://codeforces.com/contest/1795/problem/B))
## Def
> 给定n组线段和点k，判断能否通过移除线段使得k是占有最多线段的点（$l$）
## Sol
> 需要考虑的是和k有关的线段，统计每个点的相关量即可
## Code
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    int x,y;
    int f[51];
    cin>>t;
    while(t--){
        memset(f,0,sizeof(f));
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            if(x<=k&&y>=k)
            for(int j=x;j<=y;j++) f[j]++;
        }
        int fl=1;
        for(int i=1;i<=50;i++)
        if(i!=k&&f[i]>=f[k]){
            fl=0;
            break ;
        } 
        if(fl) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
```

# [C. Tea Tasting]([Problem - C - Codeforces (Unofficial mirror by Menci)](https://codeforc.es/contest/1795/problem/C))
## Sol
> 一杯茶造成的贡献分两种，整段b和一次a-$\sum b$ ，前缀和后二分查找中间的节点即可
## Code
```cpp
#include<bits/stdc++.h>
using namespace std;
const int nn=2e5+1;
int t,n;
long long sum;
long long a[nn],b[nn],c[nn],d[nn],e[nn];
int mids(int l,int r,long long x,long long *s){
    while(l<r){
        int mid=l+r>>1;
        if(s[mid]>x) r=mid;
        else l=mid+1;
    }
    return r;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],c[i]=0,d[i]=0;
        for(int i=1;i<=n;i++) cin>>b[i],e[i]=b[i],b[i]+=b[i-1];
        b[n+1]=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=n;i++){
            int k=mids(1,n+1,a[i]+b[i-1],b);
            c[i]+=1;
            c[k]-=1;
            d[k]+=a[i]+b[i-1]-b[k-1];
        }
        for(int i=1;i<=n;i++){
            c[i]+=c[i-1];
            cout<<c[i]*e[i]+d[i]<<" ";
        } 
        cout<<endl;
    }   
    return 0;
}

```
# [D. Triangle Coloring]([Problem - D - Codeforces (Unofficial mirror by Menci)](https://codeforc.es/contest/1795/problem/D))
#计数
## Sol
> 每个三角形的染色形式是固定的，称其中连有两条有效边的点为关键点，其中n/6个三角形的关键点是红色，故具体染色的系数为$(^{n/3}_{n/6})$ 
## Code
```cpp
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int nn=3e5+5;
const int mod=998244353;
int N;
int W[nn];
ll Jc[nn],InvJc[nn];
int main(){
    scanf("%d",&N);
    Jc[1]=InvJc[1]=InvJc[0]=1ll;
    for(int i=2;i<=N;i++){
        Jc[i]=i*Jc[i-1]%mod;
        InvJc[i]=InvJc[mod%i]*(mod-mod/i)%mod;
    }
    for(int i=2;i<=N;i++) InvJc[i]=InvJc[i]*InvJc[i-1]%mod;
    for(int i=1;i<=N;i++) scanf("%d",&W[i]);
    ll ans=1ll;
    for(int i=1;i<N;i+=3){
        int k=1;
        if((W[i]==W[i+1]&&W[i+2]>W[i])
        ||(W[i]==W[i+2]&&W[i+1]>W[i])
        ||(W[i+1]==W[i+2]&&W[i]>W[i+1])) k=2;
        if(W[i]==W[i+1]&&W[i+1]==W[i+2]) k=3;
        ans=ans*k%mod;
    }
    ll k1=N/6,k2=N/3;
    ll k3=Jc[k2]*InvJc[k1]%mod*InvJc[k2-k1]%mod;
    printf("%lld\n",ans*k3%mod);
    return 0;
}
```
# [E. Explosions?]([Problem - E - Codeforces (Unofficial mirror by Menci)](https://codeforc.es/contest/1795/problem/E))
#dp #数学
## Sol
> 终结技能打的伤害是一个单峰，考虑左半边，由两段组成
> 一部分是邻接的由更高伤害降低而来的等差部分，可以用求和公式计算
> 一部分是本来就小于衰减后伤害的部分，等价于该节点的伤害贡献
## Code
```cpp
#include<bits/stdc++.h>
#define ll long long
//#define debug
using namespace std;
#ifdef debug
const int nn=10;
#endif
#ifndef debug
const int nn=3e5+5;
#endif
int T,N;
int H[nn],B[nn],C[nn],S[nn];
ll F[nn],D[nn];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        ll sum=0;
        for(int i=1;i<=N;i++){
            scanf("%d",&H[i]);
            B[i]=H[i]-i;
            C[i]=H[i]+i;
            F[i]=D[i]=0;
            sum+=H[i];
        }
        F[0]=D[N+1]=0;
        int top=0; S[0]=0;
        for(int i=1;i<=N;i++){
            while(top&&B[S[top]]>=B[i]) top--;
            int k=S[top]+1; 
            S[++top]=i;
            if(top==1){ 
                k=max(i-H[i]+1,1);
                F[i]=1ll*(i-k+1)*H[i]-1ll*(i-k)*(i-k+1)/2;
                continue ;
            }
            
            F[i]=max(F[i],F[k-1]
                +1ll*(i-k+1)*H[i]-1ll*(i-k)*(i-k+1)/2);
        }
        top=0; S[0]=N+1; C[N+1]=0;
        for(int i=N;i;i--){
            while(top&&C[S[top]]>=C[i]) top--;
            int k=S[top]-1; 
            S[++top]=i;
            if(top==1){ 
                k=min(i+H[i]-1,N);
                D[i]=1ll*(k-i+1)*H[i]-1ll*(k-i)*(k-i+1)/2;
                continue ;
            }
            
            D[i]=max(D[i],D[k+1]
                +1ll*(k-i+1)*H[i]-1ll*(k-i)*(k-i+1)/2);
        }
        ll ans=0;
        for(int i=1;i<=N;i++){
            ans=max(ans,F[i]+D[i]-H[i]*2);
        }
        ans=sum-ans;
        printf("%lld\n",ans);
    }
    return 0;
}
```
# [F. Blocking Chips]([Problem - F - Codeforces (Unofficial mirror by Menci)](https://codeforc.es/contest/1795/problem/F))
#贪心 #树
## Def
> 一颗n节点的树，有k个黑色碎片，没有碎片的节点是白色，按顺序移动棋子，可以向相邻白色节点移动，然后会将其染黑，直到没法移动，问移动次数最多是多少
## Sol
> - 如何线性处理一颗树上多个节点的顺序移动 ？
> - 将顺序拆开，从终局考虑 -> 二分每个棋子的移动次数
> - 如何判断可行性？
> - 性质：节点不能跨越，所以优先考虑底层节点，发现往下走是不影响上层节点的，而往上走是唯一的，即其状态转移是确定的，对每个碎片记录所需路径长度，子树够就走子树，否则把自己的需求转移给父亲，判可行性即可
## Code
```cpp
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
```

# [G. Removal Sequences]([Problem - G - Codeforces (Unofficial mirror by Menci)](https://codeforc.es/contest/1795/problem/G))
#图论 #转化 #64状压 
## Def
> n点m边无向图，每个点有权$a_i$  
> 每次操作可以将度为$a_i$的点i移除，输入保证存在移除所有点的方案
> 问有多少点对$(x,y)$，存在两个移除方案使得一次x先于y被移除，一次x后于y被移除
## Sol
> - 当一个点度数等于点权时，它必须先于其邻点先移除
> - 因为保证了存在解，于是同时能够移除的点必不相邻
> - 且对于每个点的相邻点，它与该点的移除顺序是固定的，例如点对$(u,v)$,若$u$先移除，那么它是通过移除非v的节点达到的可移除态，而若v也可以先移除，那么它也可以通过移除非u节点达到可移除态，即这两个节点可以同时达到可移除态，与上一条性质矛盾。
> - 而相邻点间顺序的固定可构成一条依赖关系，而所有点的依赖关系将构成一张DAG图（因为有解），而图中任意可到达的点队的顺序都是固定的
> - 于是题目变为求解  有向图中不可到达的点对数目=$\frac{n*(n-1)}{2}$-可到达点对数目，DAG上状压跑即可
> - 但一般的bitset处理容易超时，出题人提供了一种想法：每次跑64个点，计算其影响，时间复杂度为$O(\frac{n^2}{64})$ 
## Code
```cpp
#include<bits/stdc++.h>
//#define debug 
#define ull unsigned long long
using namespace std;
#ifndef debug
const int nn=1e5+5;
#endif
#ifdef debug
const int nn=20;
#endif
int T,N,M;
int A[nn],D[nn];
vector<int>G[nn];
int Sta[nn];

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
        vector<ull> s(N+1);
		vector<pair<int,int> >g2;
        while(hd){
            int u=Sta[hd--];
            for(int v:G[u]){
            	if(D[v]<=A[v]) continue ;
                D[v]--;
                g2.push_back({u,v});
                if(D[v]==A[v]){
                    Sta[++hd]=v;
                }
            }
        }
        reverse(g2.begin(),g2.end()); //逆拓扑序
        long long ans=0;
        for(int l=1;l<=N;l+=64){ //每次更新64个
            int r=min(N,l+64-1);
            for(int i=l;i<=r;i++) s[i]=1ull << (i-l);
            for(auto it:g2) s[it.first]|=s[it.second]; //逆拓扑序更新
            for(int i=1;i<=N;i++){
              	ans+=__builtin_popcountll(s[i]);
				s[i]=0;           	
			}
        }
        ans=1ll*N*(N-1)/2+N-ans;
        printf("%lld\n",ans);
    }
    return 0;
}
```