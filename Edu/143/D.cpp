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