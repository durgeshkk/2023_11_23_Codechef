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
 
void solve()
{
 
    ll n;cin>>n;
    ll p,q;cin>>p>>q;
    vector<ll> v(n);enter(v);
    vector<ll> neg,pos;
    ll flag = 0;
    for(ll i=0;i<n;i++){
        if(v[i] < 0){
            neg.push_back(v[i]);
        }else if(v[i] > 0){
            pos.push_back(v[i]);
        }else{
            flag++;
        }
    }

    if(flag){
        if(!neg.size()){
            --flag;
            neg.push_back(0);
        }
        if(!pos.size()){
            --flag;
            pos.push_back(0);
        }
    }
    
    sort(all(pos));
    sort(all(neg));reverse(all(neg));
    /*
    multiset<ll> negms(all(neg));
    multiset<ll> posms(all(pos));

    while(p--){
        if(negms.size() >= 2 and posms.size() >= 2){
            ll x = *negms.begin();negms.erase(negms.find(x));
            ll y = *negms.begin();negms.erase(negms.find(y));
            ll a = *posms.rbegin();posms.erase(posms.find(a));
            ll b = *posms.rbegin();posms.erase(posms.find(a));

            if(abs(y) > b){
                negms.insert(x+y);
                posms.insert(a);posms.insert(b);
            }else{
                negms.insert(x);negms.insert(y);
                posms.insert(a+b);
            }
        }else if(posms.size() >= 2){
            ll a = *posms.rbegin();posms.erase(posms.find(a));
            ll b = *posms.rbegin();posms.erase(posms.find(a));
            posms.insert(a+b);
        }else if(negms.size() >= 2){
            ll x = *negms.begin();negms.erase(negms.find(x));
            ll y = *negms.begin();negms.erase(negms.find(y));
            negms.insert(x+y);
        }
    }*/

    ll sm = 0,mx = 0,mn = 0;
    


    
        /*
        multiset<ll> ms(all(pos));
        while(p-- and ms.size() > 2){
            ll a = *ms.rbegin();ms.erase(ms.find(a));
            ll b = *ms.rbegin();ms.erase(ms.find(b));
            ms.insert(a+b);
        }
        ll f = 0;
        while(ms.size() > 2 and q--){
            ll a = *ms.begin();ms.erase(ms.find(a));
            ll b = *ms.begin();ms.erase(ms.find(b));
            if(a >= 0 and b >= 0){
                ms.insert(a-b);
            }else{
                ms.insert(a+b);
            }
        }

        ll x = *ms.rbegin(),y = *ms.begin();
        sm = abs(x-y); */
    /*
    if(!neg.size()){
        ll ele = p+q+1;
        ll rem = max(0ll,n-ele);
        ll ok = 0;
        for(ll j = pos.size()-1;j>0 and rem;--j){
            ok += abs(pos[j]);
            --rem;
        }
        if(!flag){
            sm = abs(ok-pos[0]);
        }
    }else if(!pos.size()){
        ll ele = p+q+1;
        ll rem = max(0ll,n-ele);
        ll ok = 0;
        for(ll j = neg.size()-1;j>0 and rem;--j){
            ok += abs(neg[j]);
            --rem;
        }
        if(!flag){
            sm = abs(ok+neg[0]);
        }
    }else{*/
    multiset<ll> msn,msp;
    if(!pos.size()){
        mn = neg[neg.size()-1];neg.pop_back();
        mx = neg[0];
        for(ll i = 1;i<neg.size();++i){
            msn.insert(neg[i]);
        }
    }else if(!neg.size()){
        mx = pos[pos.size()-1];pos.pop_back();
        mn = pos[0];
        for(ll i = 1;i<pos.size();++i){
            msp.insert(pos[i]);
        }
    }else{
        mx = pos[pos.size()-1],mn = neg[neg.size()-1];
        pos.pop_back();neg.pop_back();
        for(auto it:pos){msp.insert(it);}
        for(auto it:neg){msn.insert(it);}
    }



        while(msp.size() and msn.size() and q){
            ll a = *msp.rbegin(),b = *msn.begin();
            msp.erase(msp.find(a));msn.erase(msn.find(b));
            if(a > abs(b)){
                mn -= a;
                msn.insert(b);
            }else{
                msp.insert(a);
                mx -= b;
            }
            --q;
        }

        while(msp.size() and q){
            ll a = *msp.rbegin();
            msp.erase(msp.find(a));
            mn -= a;
            --q;
        }

        while(msn.size() and q){
            ll b = *msn.begin();
            msn.erase(msn.find(b));
            mx -= b;
            --q;
        }

        while(msp.size() and msn.size() and p){
            ll a = *msp.rbegin(),b = *msn.begin();
            msp.erase(msp.find(a));msn.erase(msn.find(b));
            if(a > abs(b)){
                mx += a;
                msn.insert(b);
            }else{
                msp.insert(a);
                mn += b;
            }
            --p;
        }

        while(msn.size() and p){
            ll b = *msn.begin();
            msn.erase(msn.find(b));
            mn += b;
            --p;
        }

        while(msp.size() and p){
            ll b = *msp.rbegin();
            msn.erase(msp.find(b));
            mx += b;
            --p;
        }

        sm = mx-mn;
        /*
        // for(ll i = pos.size()-1;i>=0 and q--;--i){
        //     mn -= pos[i];
        // }
        // for(ll i = neg.size()-1;i>=0 and p--;--i){
        //     mx -= neg[i];
        // }

        // while(p || q){
        //     if(q and p){
        //         if(p > q){
        //             ll a = pos[pos.size()-1],b = neg[neg.size()-1];
        //             pos.pop_back();neg.pop_back();

        //             --p;
        //         }else{

        //             --q;
        //         }
        //     }else{
        //         if(p){
        //             --p;
        //         }else{

        //             --q;
        //         }
        //     }
        // }
        // sm = mx-mn;
        // ll i = 0,j = 0;
        // ll ele = p+q+2;
        // ll rem = max(0ll,n-ele);
        // ll cntr = 0;
        // while((rem > cntr) and (i<neg.size()) and (j <pos.size())){
        //     ++cntr;
        //     ll a = abs(neg[i]);
        //     if(a > pos[j]){
        //         ++j;
        //     }else{
        //         ++i;
        //     }
        // }
        // while((rem > cntr) and (i<neg.size())){
        //     ++cntr;++i;
        // }
        // while((rem > cntr) and (j <pos.size())){
        //     ++cntr;++j;
        // }

        // for(ll idx = i;idx<neg.size();++idx){
        //     sm += abs(neg[idx]);
        // }
        // for(ll idx = j;idx<pos.size();++idx){
        //     sm += abs(pos[idx]);
        // }*/
        /*
        // while(1){
        //     if(q>=2){
        //         if(neg.size() >= 2 and pos.size() >= 2){
        //             ll a = pos[pos.size()-1],b = pos[pos.size()-2];
        //             ll c = neg[neg.size()-1],d = neg[neg.size()-2];
        //             neg.pop_back();neg.pop_back();pos.pop_back();pos.pop_back();
        //             pos.push_back(a-d);neg.push_back(c-b);
        //             q -= 2; 
        //         }
        //     }else if(q){
        //         if(neg.size() == 1){
        //             ll a = pos[pos.size()-1],b = pos[pos.size()-2];
        //             pos.pop_back();pos.pop_back();

        //             ll c = neg[neg.size()-1];neg.pop_back();

        //         }else if(pos.size() == 1){
                    
        //         }else{break;}
        //         --q;
        //     }else{break;}
        //     }
        // }
    // }
        */
    cout<<sm<<endl;
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