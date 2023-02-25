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