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
 
    ll n,k;
    cin>>n>>k;

    vector<ll> v;
    if((k+n) < 20000){
        for(ll i=0;i<n;i++){
            v.push_back(k+1+i);
        }
    }
    else{
        if(k < 19500){
            for(ll i=0;i<n/2;i++){
                v.push_back(k+i);
                v.push_back(k-i);
            }
        }
        else if(k < 20000){
            ll t = 0;
                t = 20000-k;

            for(ll i=t+1;i<20000;i++){
                v.push_back(i);
            }

            ll rem = n - v.size();
            for(ll i=0;i<rem;i++){
                v.push_back(k-i-1);
            }
        }
        else{
           for(ll i=0;i<n;i++){
                v.push_back(i+1);
            } 
        }
    }

    for(ll i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

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