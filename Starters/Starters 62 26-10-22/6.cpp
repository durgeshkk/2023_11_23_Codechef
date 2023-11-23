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

bool fermat(ll n){
    for (ll i = 2;i * i <= n; i++){
        ll count = 0;
        if (n % i == 0){
            // Count all the prime factors.
            while (n % i == 0){
                ++count;
                n /= i;
            }
    
            // Ifany prime factor of the form
            // (4k+3)(4k+3) occurs an odd
            // number of times.
            if (i % 4 == 3 && count % 2 != 0)
                return false;
        }
    }
    
    // If n itself is a x prime number and
    // can be expressed in the form of
    // 4k + 3 we return false.
    return n % 4 != 3;
}

map<ll,pair<ll,ll>> mp;
void solve(){
    // for(ll i = 0;i<1e5;++i){cout<<500000000000000<<" ";}return;
    ll n;cin>>n;
    ll m = (sqrt(n));

    bool f = 1;
    ll b;double d;
    for(ll j = 1;j*j<=n;++j){
        ll s = n-(j*j);
        b = sqrt(s);
        d = sqrt(s);
        if(b == d){
            cout<<j<<" "<<b<<endl;f=0;return;
        }
    }
    if(f & 1){
        if(m*m==n){cout<<"0 "<<m<<endl;}
        else{cout<<"-1\n";}
    }
/*

    m = min(m,100000ll);

    if(mp.find(n) != mp.end()){
        cout<<mp[n].first<<" "<<mp[n].second<<endl;return;
    }

    // if(fermat(n)){
        for(ll i = 0;i<=m;++i){
            double b = sqrt(n-(i*i));
            ll a = (ll)b;
            if(a == b){
                mp[n] = {i,b};
                cout<<i<<" "<<b<<endl;return;
            }
            // ll a = (n-(i*i));
            // if(Psq(a)){cout<<i<<" "<<sqrt(a)<<endl;return;}
            // if(s.find(a) != s.end()){cout<<i<<" "<<mp[a]<<endl;return;}
        }
        // cout<<"1\n";
    // }
    // else{
        cout<<"-1\n";
        // }
    return;
    // for(auto it:s){cout<<it<<" ";}cout<<endl;

    cout<< -1 <<endl;
*/
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
//    sq();
    // pS(0,1e9);
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
/*
    for(ll i=0;i<=m;i++){
        for(ll j = 0;j<=m;++j){
            ll a = i*i+j*j;
            if(a == n){
                cout<<i<<" "<<j<<endl;return;
            }
        }
    }
    cout<< -1<<endl;
*/