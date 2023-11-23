#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n,x;
    cin>>n>>x;

    vector<ll> v;
    for(int i=0;i<n-1;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
    }

    ll sum = accumulate(v.begin(),v.end(),0);

    ll ans=((x*n)-sum);

    if(ans >= 0){
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}