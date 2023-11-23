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
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if(n<2 || n%2==0 || n%3==0){
       return false;
   }
   
   for(int i=5; i*i <= n; i+=6){
      if(n%i==0 || n%(i+2)==0){
         return false;
      }
   }
   return true;
}
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
}
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
 
 
ll fact[100005];
ll powfact[100005];
void precomputefact(){
    fact[0] = 1;
    ll ans = 1;
    for(ll i = 1;i<=100005;++i){
         ans = (ans*i)%mod;
         fact[i] = ans;
         powfact[i] = power(fact[i],mod-2,mod);
    }
}
 
ll nCr(ll n,ll r){
     ll at = powfact[r];
     ll at2 = powfact[n-r];
     return ((fact[n]*((at*at2)%mod))%mod);
}
 
vector<ll> adj[100004];
 
void bfs(){
    queue<pair<ll,ll>> q;
    q.push({1,0});
 
    while(!q.empty()){
        auto it = q.front();
        q.pop();
 
        ll node = it.first;
        ll par = it.second;
 
        cout<<node<<" ";
 
        for(auto it:adj[node]){
            if(it != par){
                q.push({it,node});
            }
        }
    }
}
 
ll height;
ll subtree[100005];
ll lev[100005];
ll parent[200005];
 
void dfs(ll node, ll par, ll level=1){

    cout<<node<<" ";
    lev[node] = level;
    height = max(height,level);
 
    ll sm = 0;
 
    parent[node] = par;
    for(auto it:adj[node]){
        if(it != par){
            dfs(it,node,level+1);
            sm += subtree[it];
        }
    }
    subtree[node] = 1+sm;
}
 
void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
ll n;
vector<ll> v; 
/*
bool check(ll mid){
    multiset<ll> ms(v.begin(),v.end());
    multiset<ll> tmp(v.begin(),v.end());
    cout<<mid<<endl;

    for(ll i = 0;i<n;++i){
        ms.erase(ms.find(v[i]));
        tmp = ms;
        for(ll j = i+1;j<n;++j){
            tmp.erase(tmp.find(v[j]));

            ll alpha = 3*(mid)+2*v[j]-(v[i]);
            ll beta = 2*v[j] - 3*(mid)+(v[i]);

            ll a = alpha,b = a+1,c = a+2;
            ll d = beta,e = d+1,f = d+2;

            if(mid == 3 and i == 0){
                cout<<"Apl : ";
                cout<<a<<" "<<b<<" "<<c<<endl;
            }

            if(tmp.find(a) != tmp.end()){
                return true;
            }   
            if(tmp.find(b) != tmp.end()){
                return true;
            }
            if(tmp.find(c) != tmp.end()){
                return true;
            }

            if(mid == 3 and i == 0){
                cout<<"beta : ";
                cout<<a<<" "<<b<<" "<<c<<endl;
            }
            if(tmp.find(d) != tmp.end()){
                return true;
            }   
            if(tmp.find(e) != tmp.end()){
                return true;
            }
            if(tmp.find(f) != tmp.end()){
                return true;
            }
        }
    }
    return false;
}
*/
bool check(ll ans){
    multiset<ll> ms(v.begin(),v.end());
    multiset<ll> tmp(v.begin(),v.end());

    for(ll i = 0;i<n-1;++i){
        ms.erase(ms.find(v[i]));
        if(ms.empty()){continue;}
        tmp = ms;

        for(ll j = i+1;j<n;++j){
            tmp.erase(tmp.find(v[j]));
            if(tmp.empty()){continue;}

            ll req1 = ans+2*v[j]-v[i];
            ll req2 = 2*v[j]-ans-v[i];
            for(ll k = 0;k<3;++k){
                if(tmp.find(k+req1) != tmp.end()){
                    return true;
                }

                if(tmp.find(k+req2) != tmp.end()){
                    return true;
                }
            }
        }
    }
    return false;
}


void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    multiset<ll> ms(v.begin(),v.end());
    multiset<ll> tmp(v.begin(),v.end());

    sort(v.begin(),v.end());
    ll ans = LLONG_MAX;
    ll mid = 3*v[1];
    ll m = v[0]+v[1]+v[2];
    ans = abs(m-mid);
    for(ll i=0;i<n-1;i++){
        mid = 3*v[i];
        for(ll j = 0;j<i;++j){
            m = v[j];
            m += v[i];
            ll dk = mid - m;
            if(dk == v[i]){
                ans = min(ans,abs(mid-(m+v[i+1])));
            }else if(dk > v[i]){
                ll idx = lower_bound(v.begin(),v.end(),dk)-v.begin();
                if(idx <= i || idx != n){
                    ans = min(ans,abs(m-(mid-v[idx])));
                }--idx;
                if(idx <= i){}
                else{
                    ans = min(ans,abs(m-(mid-v[idx])));
                }
            }
        }
    }
    cout<<ans<<endl;return;







    ll z = LLONG_MAX;
    for(ll i=0;i<n-1;i++){
        ms.erase(ms.find(v[i]));
        if(ms.empty()){continue;}
        tmp = ms;

        for(ll j = i+1;j<n;++j){
            tmp.erase(tmp.find(v[j]));
            if(tmp.empty()){continue;}

            ll a = v[i],b = v[j];
            // ll c = abs(2*b-a);
            ll c = b;

            // 2 ele can be close to c
            // cout<<a<<" "<<b<<" "<<c<<"\n";
            auto it = tmp.lower_bound(c);
            if(tmp.end() == it){--it;}
            c = (*it);

            // cout<<a<<" "<<b<<" ";
            ll sa = abs((a-b) + (c-b));
            ans = min(ans,sa);

            ll m = (a+b+c)/3;
            z = min(z,abs(m-b));
            // cout<<c<<" "<<sa<<endl;

            // ll sa = abs((m)-b);
            // cout<<c<<" ";
            // cout<<sa<<endl;

            if(it != tmp.begin()){--it;}
            c = (*it);
            sa = abs((a-b) + (c-b));
            ans = min(ans,sa);
            m = (a+b+c)/3;
            z = min(z,abs(m-b));
            // cout<<c<<" "<<sa<<endl;
            // m = (a+b+c)/3;
            // sa = abs((m)-b);
            // cout<<c<<" ";
            // cout<<sa<<endl;
        }
    }
    z *= 3;
    ans = min(ans,z);
    cout<<ans<<endl;
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
    return;
}
 
void solver()
{
 
    cin>>n;
    v.assign(n,0);enter(v);
    // show(v);
    ll l = 0,r = 1e10,ans = LLONG_MAX;
    /*
    multiset<ll> ms(v.begin(),v.end());
    multiset<ll> tmp(v.begin(),v.end());

    for(ll i = 0;i<n;++i){
        ms.erase(ms.find(v[i]));

        if(ms.empty()){continue;}
        tmp = ms;
        for(ll j = i+1;j<n;++j){
            tmp.erase(tmp.find(v[j]));
            if(tmp.empty()){continue;}
            ll a = v[i],b = v[j];//now search for c
            ll c = (b-a);
            ll d = (a-b);

            auto it = tmp.lower_bound(c);
            if(it == tmp.end()){
                // No such ans exists 
                --it;
            } 
            c = *it;
            ll sa = abs((((a+b+c)/3)-b));
            // if(sa == 1){
            //     cout<<a<<" "<<b<<" "<<c<<endl;
            // }
            ans = min(ans,sa);

            auto it2 = tmp.lower_bound(d);
            if(it2 != tmp.begin()){
                --it2;
            }
            d = *it2;
            sa = abs((((a+b+d)/3)-b));
            // if(sa == 1){
                // cout<<a<<" "<<b<<" "<<d<<endl;
            // }
            ans = min(ans,sa);
        }
    }*/
    // /*
    while(l <= r){
        ll mid = (l+r)/2;
        cout<<mid<<endl;
        if(check(mid)){
            ans = mid;
        }
        r = mid-1;
    }
    // ans *= 3;
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