#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
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
 

void solve()
{
 
    ll n;
    cin>>n;
    ll q;
    cin>>q;

    ll arr[n+1] = {0};
    set<pair<ll,ll>> s;
    for(ll i = 1;i<=n;++i){
        s.insert({i,n});
    }

    map<ll,vector<ll>> mp;
    for(ll i=0;i<q;i++){
        ll x,y;
        cin>>x>>y;

        mp[y].push_back(x);
        s.erase({x,n});
    }

    for(auto it:mp){
        vector<ll> vec = it.second;
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        mp[it.first] = vec;
    }
/*
    for(auto it:mp){
        cout<<it.first<<" -- > ";
        vector<ll> vec = it.second;
        for(ll i = 0;i<vec.size();++i){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
*/

    for(auto it:mp){
        ll val = it.first;
        vector<ll> vec = it.second;

        for(ll i = 0;i<vec.size();++i){
            ll f= 0;
            ll ak = vec[i];
            if(vec[i] >= val){
                for(ll j = val;j>0;--j){
                    if(arr[j] == 0){
                        arr[j] = ak;
                        f = 1;
                        break;
                    }
                }

                if(f == 0){
                    cout<< -1 <<endl;
                    return;
                }
            
                val--;
            }
            else{
                s.insert(make_pair(ak,val));
                // break;
            }
        }
    }

    // cout<<"HI\n";

    ll fl = 0;
    for(ll i = n;i>0;--i){
        if(arr[i] == 0){
            ll mx = *s.rbegin();
            
            if(ms.empty() && s.empty()){
                return;
            }

            if(ms.empty()){
                fl = 1;
                break;
            }

            if(s.empty()){
                fl = 2;
                break;
            }

            pair<ll,ll> p = *ms.rbegin();

            if(mx > p.first){
                arr[i] = mx;
                s.erase(mx);
            }
            else{
                ll id = p.second;
                if(id <= i){
                    arr[i] = mx;
                    s.erase(mx);
                }
                else{
                    arr[i] = p.first;
                    ms.erase(p);
                }
            }
        }

    }

    if(fl == 1){
        for(ll i = 1;i<=n;++i){
            if(arr[i] == 0){
                arr[i] = *s.begin();
                s.erase(arr[i]);
            }
        }
    }

    if(fl == 2){
        for(ll i = 1;i<=n;++i){
            pair<ll,ll> p = *ms.begin();
            if(arr[i] == 0){
                arr[i] = p.first;
                ms.erase(p);
            }
        }
    }

    for(ll i = 1;i<=n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}


/*
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
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
 

void solve()
{
 
    ll n;
    cin>>n;
    ll q;
    cin>>q;

    ll arr[n+1] = {0};
    set<ll> s;
    for(ll i = 1;i<=n;++i){
        s.insert(i);
    }


    map<ll,vector<ll>> mp;
    for(ll i=0;i<q;i++){
        ll x,y;
        cin>>x>>y;

        mp[y].push_back(x);
        s.erase(x);
    }

    for(auto it:mp){
        vector<ll> vec = it.second;
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        mp[it.first] = vec;
    }
/*
    for(auto it:mp){
        cout<<it.first<<" -- > ";
        vector<ll> vec = it.second;
        for(ll i = 0;i<vec.size();++i){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
*/
    


    set<pair<ll,ll>> ms;
    for(auto it:mp){
        // cout<<"HI\n";
        ll val = it.first;
        vector<ll> vec = it.second;

        // cout<<val<<" ";
        for(ll i = 0;i<vec.size();++i){
            ll f= 0;
            ll ak = vec[i];
            if(vec[i] >= val){
                for(ll j = val;j>0;--j){
                    if(arr[j] == 0){
                        arr[j] = vec[i];
                        f = 1;
                        break;
                    }
                }

                if(f == 0){
                    cout<< -1 <<endl;
                    return;
                }
            
                val--;
            }
            else{
                // if(val == 2){
                //     cout<<"1 \n";
                //     cout<<ak<<endl;
                //     cout<<it.first<<endl;
                //     continue;
                // }
                ms.insert(make_pair(ak,val));
                break;
            }
        }
    }

    // cout<<"HI\n";

    ll fl = 0;
    for(ll i = n;i>0;--i){
        if(arr[i] == 0){
            ll mx = *s.rbegin();
            
            if(ms.empty() && s.empty()){
                return;
            }

            if(ms.empty()){
                fl = 1;
                break;
            }

            if(s.empty()){
                fl = 2;
                break;
            }

            pair<ll,ll> p = *ms.rbegin();

            if(mx > p.first){
                arr[i] = mx;
                s.erase(mx);
            }
            else{
                ll id = p.second;
                if(id <= i){
                    arr[i] = mx;
                    s.erase(mx);
                }
                else{
                    arr[i] = p.first;
                    ms.erase(p);
                }
            }
        }

    }

    if(fl == 1){
        for(ll i = 1;i<=n;++i){
            if(arr[i] == 0){
                arr[i] = *s.begin();
                s.erase(arr[i]);
            }
        }
    }

    if(fl == 2){
        for(ll i = 1;i<=n;++i){
            pair<ll,ll> p = *ms.begin();
            if(arr[i] == 0){
                arr[i] = p.first;
                ms.erase(p);
            }
        }
    }

    for(ll i = 1;i<=n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    /*
        ll idx = y-1;
        // if(arr[idx] != 0){
            ll f = 0;
            for(ll i = idx;i>=0;--i){
                if(arr[i] == 0){
                    f = 1;
                    arr[i] = x;
                    s.erase(x);
                }
            }

            if(f == 0){
                cout<< -1 <<endl;
                return;
            }
        // }
        // else{
        //     arr[idx] = x;
        //     s.erase(x);
        // }
    }

    for(ll i = 1;i<=n;++i){
        if(arr[i] == 0){
            arr[i] = *s.begin();
            s.erase(arr[i]);
        }
        cout<<arr[i]<<" ";
    }
    cout<<endl;
*/
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}