#include<bits/stdc++.h>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
 
void solve()
{
 
    ll n,k;cin>>n>>k;
    vector<ll> v(n);enter(v);
    set<ll> s;
    forj(n){s.insert(j+1);}

    vector<ll> ans(n,0);
    forj(n){
        ll x = n-j-1,y = j;
        if(x >= k || y>=k){
        }else{
            ans[j] = v[j];
            s.erase(s.find(ans[j]));
        }
    }

    forj(n){
        if(!ans[j]){
            ans[j] = *s.begin();
            s.erase(s.find(*s.begin()));
        }
    }
    show(ans);
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   return 0;
}