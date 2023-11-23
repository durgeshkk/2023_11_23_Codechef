#include<bits/stdc++.h>
// #include <bit>
#include <bitset>
#include <cstdint>
#include<iomanip>
#include <deque>
#define ll long long int
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
 
vector<ll> precomp;
void pre(){
    for(ll i = 0;i<63;++i){
        ll mask = (1ll<<i);
        mask--;
        precomp.push_back(mask);
    }
}


void solve()
{
 
//     ll val = __builtin_popcount(5);
//    cout<<val<<endl;

    ll n,k;
    cin>>n>>k;
    
    ll i= 0;
    while((precomp[i]*n)<k){
        ++i;
    }

    ll a = precomp[i];
    ll b = precomp[i-1];

    // __builtin_popcount

    ll bita = __builtin_popcount(a);
    ll bitb = __builtin_popcount(b);

    ll upper = k-(b*n);
    ll lower = a-(b);

    ll x = (upper/lower) + (upper%lower ? 1:0);
    ll y = (n-x);

    ll ans = x*bita + y*bitb;
    ans -= (__builtin_popcount(x*a + y*b - k));
    cout<< ans << endl;
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
    pre();
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}