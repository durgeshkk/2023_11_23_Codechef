#include<bits/stdc++.h>
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
 
void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v;

    ll ones = 0,zero=0;

    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);

       if(ele == 1){
           ones++;
       }
       else{
           zero++;
       }
    }

    if(ones>=zero){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}