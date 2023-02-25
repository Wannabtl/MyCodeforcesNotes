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