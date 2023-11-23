#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#define ll long long int
using namespace std;
 
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
void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

// Var Declaration : 
    ll fl = 0,t=0;
    ll cnt = 0,lt = 0;
    ll val = 1e18;
    map<ll,ll> m;

    ll i = 0;
    for (i;i<n;++i){

        if (m.find(v[i]) == m.end()){
            cnt++;
        }
        else{
            // val = min(val,n-cnt+min((n-i),lt));
            lt = max((m[v[i]]+1),lt) ;
            cnt = (i-(lt)+1);
        }
         
        m[v[i]] = i;
        val = min(val,n-cnt+min((n-i-1),lt));
    }

    cout<<val<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   ll tt=1;
   cin >> tt;
   while (tt--)
   {
       solve();
   }
   //solve();
   return 0;
}

