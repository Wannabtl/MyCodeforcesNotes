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
