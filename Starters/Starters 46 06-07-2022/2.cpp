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
 
vector<ll> val1(ll x,ll y){
    ll a = 2;
    ll b = 2^x;  
    ll c = b^y;  

    vector<ll> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    ll cnt = 0;
    for(ll i = 0;i<3;++i){
        v[i]%= 2;
        if(v[i] == 0){
            cnt++;
        }
    }

    if(cnt == 1){
        v.clear();
        v.push_back(2);
        v.push_back(min(b,c));
        v.push_back(max(b,c));
        return v;
    }
    v.clear();
    return v;    
}

vector<ll> val2(ll x,ll y){
    ll b = 2;
    ll a = 2^x;  
    ll c = b^y;  

    vector<ll> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    ll cnt = 0;
    for(ll i = 0;i<3;++i){
        v[i]%= 2;
        if(v[i] == 0){
            cnt++;
        }
    }

    if(cnt == 1){
        v.clear();
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        return v;
    }
    v.clear();
    return v;    
}

vector<ll> val3(ll x,ll y){
    

}

void solve()
{
 
    ll x,y;
    cin>>x>>y;
    /*
    vector<ll> res = val1(x,y);

    res  = 

    ll c = a^b;

    ll x = a,y=b,z = c;
    // cout<<x<<y<<z<<endl;
    for(ll a = 2;a<40;++a){
        b = x^a;
        c = y^b;

        for(ll j = b;)
        if(b != 1 && c != 1){
            vector<ll> v;
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
            sort(v.begin(),v.end());
            show(v);
            return;
        }
    }
    // a = 3;
    // b = z^y;
    // c = z^x;
    */
    
    ll a = 2;
    ll b = 2^x;  
    ll c = b^y;  

    vector<ll> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    ll cnt = 0;
    for(ll i = 0;i<3;++i){
        v[i]%= 2;
        if(v[i] == 0){
            cnt++;
        }
    }

    if(cnt == 1){
        v.clear();
        v.push_back(2);
        v.push_back(min(b,c));
        v.push_back(max(b,c));
        sort(v.begin(),v.end());
        show(v);
        return;
    }
    v.clear();

    b = 2;
    a = 2^x;  
    c = b^y;  

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    cnt = 0;
    for(ll i = 0;i<3;++i){
        v[i]%= 2;
        if(v[i] == 0){
            cnt++;
        }
    }

    if(cnt == 1){
        v.clear();
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end());
        
        show(v);
        return;
    }

    v.clear();


    c = 2;
    b = 2^y;  
    a = b^x;  

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    cnt = 0;
    for(ll i = 0;i<3;++i){
        v[i]%= 2;
        if(v[i] == 0){
            cnt++;
        }
    }

    if(cnt == 1){
        v.clear();
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end());
        show(v);
        return;
    }
    sort(v.begin(),v.end());
    show(v);
    // v.clear();

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   createsieve();
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