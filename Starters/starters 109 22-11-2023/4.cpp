/*
Once in a LifeTime,
Will never let you Down!!
*/
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
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
/*
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
*/
 
// Fxn call(for ((b/a)%mod)) :
// ll c = (b*power(a,mod-2(prime num in power of a),mod))%mod;
// Also for formula like nCr..
ll power(ll base,ll n,ll mod){
   ll ans = 1;
   while( n!= 0){
      if(n%2){
          n-=1;
          ans = (ans*base)%mod;
      }
      else{
          n /= 2;
          base = (base*base)%mod;
      }
   }
   return ans;
}
 
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
 
ll sieve[1000005];
void createsieve(){
    ll ntlen = 1000000;
    sieve[0] = 0;
    sieve[1] = 0;
    for(ll i = 2;i<=ntlen;++i){
        sieve[i] = 1;
    }
 
    for(ll i = 2;i*i<=ntlen;++i){
 
        // Set all multiples to 0
        if(sieve[i] == 1){
 
            for(ll j = i*i;j<=ntlen;j+=i){
                 sieve[j] = 0;
            }
        }
    }
}
 
 
vector<ll> adj[100004];
 
void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
// YE DIL MAANGE MORE!!

// A,CA,B,CB 
void yno(ll f){
   if(f & 1) cout<<"Yes\n";
   else cout<<"No\n";
   return;
}
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> a(n);enter(a);
    vector<ll> colorA(n);enter(colorA);
    vector<ll> b(n);enter(b);
    vector<ll> colorB(n);enter(colorB);

    // show(a);
    // show(colorA);

    map<ll,multiset<ll>> mpA,mpB;

    for(ll i=0;i<n;i++){
        mpA[colorA[i]].insert(a[i]);
        // mpA[colorB[i]].insert(b[i]);
    }
 
    ll mn = LLONG_MAX,sa = 1;
    for(ll i = n-1;i>=0;--i){
        ll ele = b[i],x = -1;
        if(!mpA[colorB[i]].empty()){
            multiset<ll> &ms = mpA[colorB[i]];
            auto it = ms.upper_bound(mn);

            ll f = 0;
            if(it == ms.begin()){
                f = 1;
            }

            if(!f){
                --it;
                x = *it;
            }

            if(ele <= x){
                ms.insert(ele);
                ms.erase(ms.find(x));
                b[i] = x;
                mn = x;
            }else{
                if(b[i] > mn){
                    sa = 0;
                }
                mn = b[i];
            }
        }else{
            if(b[i] > mn){sa = 0;}
            mn = b[i];
        }
    }


    for(ll i = 0;i<n;++i){
        multiset<ll> &ms = mpA[colorA[i]];
        a[i] = *ms.begin();
        ms.erase(ms.find(a[i]));
    }

    if(sa and is_sorted(all(a)) and is_sorted(all(b))){
        yno(1);return;
    }else{
        
        mpA.clear();mpB.clear();
        for(ll i=0;i<n;i++){
            mpA[colorB[i]].insert(b[i]);
            // mpA[colorB[i]].insert(b[i]);
        }
    
        ll mn = LLONG_MAX,sa = 1;
        for(ll i = n-1;i>=0;--i){
            ll ele = a[i],x = -1;
            if(!mpA[colorA[i]].empty()){
                multiset<ll> &ms = mpA[colorA[i]];
                auto it = ms.upper_bound(mn);

                ll f = 0;
                if(it == ms.begin()){
                    f = 1;
                }

                if(!f){
                    --it;
                    x = *it;
                }

                if(ele <= x){
                    ms.insert(ele);
                    ms.erase(ms.find(x));
                    a[i] = x;
                    mn = x;
                }else{
                    if(a[i] > mn){
                        sa = 0;
                    }
                    mn = a[i];
                }
            }else{
                if(a[i] > mn){sa = 0;}
                mn = a[i];
            }
        }


        for(ll i = 0;i<n;++i){
            multiset<ll> &ms = mpA[colorB[i]];
            b[i] = *ms.begin();
            ms.erase(ms.find(b[i]));
        }   

        if(sa and is_sorted(all(a)) and is_sorted(all(b))){
            yno(1);return;
        }else{
            mpA.clear(),mpB.clear();
            for(ll i=0;i<n;i++){
                mpA[colorA[i]].insert(a[i]);
                mpA[colorB[i]].insert(b[i]);
            }
        
            ll mn = LLONG_MAX,sa = 1;
            for(ll j = n-1;j>=0;--j){
                ll color = colorA[j];
                multiset<ll> &ms = mpA[color];
                auto it = ms.upper_bound(mn);
                if(it == ms.begin()){
                    sa = 0;break;
                    // cout<<"HI\n";
                    // yno(0);return;
                }else{--it;}
                a[j] = *it;
                ms.erase(ms.find(a[j]));
                mn = a[j];
            }

            mn = LLONG_MAX;
            for(ll j = n-1;j>=0;--j){
                ll color = colorB[j];
                multiset<ll> &ms = mpA[color];
                auto it = ms.upper_bound(mn);
                if(it == ms.begin()){
                    sa = 0;break;
                    // cout<<"HI2\n"<<j<<endl;
                    // yno(0);return;
                }else{--it;}
                b[j] = *it;
                ms.erase(ms.find(b[j]));
                mn = b[j];
            }

            if(sa and is_sorted(all(a)) and is_sorted(all(b))){
                yno(1);return;
            }else{
                mpA.clear();mpB.clear();
                for(ll i=0;i<n;i++){
                    mpA[colorA[i]].insert(a[i]);
                    mpA[colorB[i]].insert(b[i]);
                }
            
                mn = LLONG_MAX;
                for(ll j = n-1;j>=0;--j){
                    ll color = colorB[j];
                    multiset<ll> &ms = mpA[color];
                    auto it = ms.upper_bound(mn);
                    if(it == ms.begin()){
                        sa = 0;break;
                        // cout<<"HI2\n"<<j<<endl;
                        // yno(0);return;
                    }else{--it;}
                    b[j] = *it;
                    ms.erase(ms.find(b[j]));
                    mn = b[j];
                }

                mn = LLONG_MAX,sa = 1;
                for(ll j = n-1;j>=0;--j){
                    ll color = colorA[j];
                    multiset<ll> &ms = mpA[color];
                    auto it = ms.upper_bound(mn);
                    if(it == ms.begin()){
                        sa = 0;break;
                        // cout<<"HI\n";
                        // yno(0);return;
                    }else{--it;}
                    a[j] = *it;
                    ms.erase(ms.find(a[j]));
                    mn = a[j];
                }
                // show(a);
                // show(b);
                if(sa and is_sorted(all(a)) and is_sorted(all(b))){
                    yno(1);return;
                }
                yno(0);
            }
        }
    }
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