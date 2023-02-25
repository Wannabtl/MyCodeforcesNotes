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