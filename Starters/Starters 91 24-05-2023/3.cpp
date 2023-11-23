#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
 
    ll n,k;
    cin>>n>>k;
    ll e = n/2,o = n-e;
    ll baaki = (o-k);
    if((k <= e)){
        if(baaki%2){
            cout<<"no\n";
        }else{
            cout<<"yes\n";
        }
    }else{
        cout<<"no\n";
    }
    return;
}
 
signed main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}