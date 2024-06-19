/*
Once in a LifeTime,
Will never let you Down!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
#define pyes cout << "YES" << endl;
#define pno cout << "NO" << endl;
using namespace std;
ll mod = (ll)(1e9+7);

vector<int> spf;
vector<int> primes;

void sieve(int N){
    spf.resize(N);
    iota(all(spf), 0);
    for(ll i = 2; i * i <= N; i++){
        if(spf[i] != i){
            continue;
        }
        for(ll j = 2 * i; j < N; j += i){
            if(spf[j] == j)
                spf[j] = i;
        }
    }
    for(int i = 2; i < N; i++){
        if(spf[i] == i){
            primes.push_back(i);
        }
    }
}

//  "A" : 65, "a" : 97  (-> |) (<- &(~))
// YE DIL MAANGE MORE!!
// const long long MAX_SIZE = 1000001;
// vector<long long> isprime(MAX_SIZE , true);
// vector<long long> prime;
// vector<long long> SPF(MAX_SIZE);

void solve(){
    long long n;cin>>n;

    long long ans = 0;
    for(auto it:primes){
        if(it <= spf[n]){
            ans += (it);
        }else{break;}
    }
    cout<<ans*n<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sieve(1000000);
    
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}