#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n,0);
    if(n%2 == 0){
        for(ll i=1;i<=n;i++){
            v[i-1] = (i);
        }

        for(ll i=n-1;i>=0;i--){
            cout<<v[i]<<" ";
        }cout<<endl;
        return;
    }
    cout<<"-1\n";
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}