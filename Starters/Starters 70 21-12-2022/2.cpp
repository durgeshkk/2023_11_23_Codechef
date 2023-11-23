#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
bool prime[100001];
map<ll,ll> s;
void SieveOfEratosthenes(ll n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    memset(prime, true, sizeof(prime));
 
    for (ll p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    for (ll p = 2; p <= n; p++)
        if (prime[p])
            s[p]++;
}

void solve()
{
    
    ll n;cin>>n;
    string a,b;cin>>a>>b;

    ll cnt = 0;
    for(ll i = 0;i<n;++i){
        if(a[i] == '1'){++cnt;}
        if(b[i] == '1'){--cnt;}
    }

    ll flag = 1;
    if(cnt != 0){
        flag = 0;
    }

    /*
    ll idx = -1,i = 0,f = 0;
    while(i < n){
        if(a[i] != b[i]){
            if(f == 0){
                idx = i;
            }else{
                ll diff = (i-idx+1);
                if(s.find(diff) == s.end()){
                    flag = 0;break;
                }
                idx = -1;
            }
            f ^= 1;
        }
        ++i;
    }*/
 
    if((flag & 1)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   SieveOfEratosthenes(100000);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
    
    // for(auto it:s){
    //     cout<<it.first<<" ";
    // }cout<<endl;
    // show(prime);
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