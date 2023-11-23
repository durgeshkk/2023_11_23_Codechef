#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

/*
if (type == 1):
    if (a > b):
        score = score + 1;
    else:
        a = 0;
        b = 0;
else:
    if (a < b):
        score = score + 1;
    else:
        a = 0;
        b = 0; 
*/

ll n,m;
vector<ll> tym,type;
map<ll,ll> mp;
map<vector<ll>,ll> dp;

ll recur(ll i,ll a,ll b,ll ans){
    if(i > n){
        return ans;
    }

    if(dp.find({i,a,b}) != dp.end()){
        return dp[{i,a,b}];
    }

    if(mp.find(i) != mp.end()){
        ll ty = mp[i];
        if(ty == 1){
            if(a > b){
                ans++;
            }
            else{
                a = 0,b = 0;
            }
        }else{
            if(a < b){
                ans++;
            }
            else{
                a = 0,b = 0;
            }
        }
    }

    // call recur
    ll ans1 = recur(i+1,a+1,b,ans);
    ll ans2 = recur(i+1,a,b+1,ans);
    
    return dp[{i,a,b}] = max(ans1,ans2);
}

void solve()
{
    mp.clear();dp.clear();

    cin>>n>>m;
    tym.assign(m+1,0);
    type.assign(m+1,0);

    for(ll i=1;i<=m;i++){
        cin>>tym[i];
    }
    for(ll i=1;i<=m;i++){
        cin>>type[i];
        mp[tym[i]] = type[i];
    }

    ll ans = recur(0,0,0,0);
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}