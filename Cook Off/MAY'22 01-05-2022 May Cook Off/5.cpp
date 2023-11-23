#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }

    sort(v.begin(),v.end());

    vector<ll> diff;
    for(int i=1;i<n;i++){
        diff.push_back(v[i]-v[i-1]);
    }

    for(int i = 0;i<diff.size()-1;i++){
        ll a = 2*diff[i];
        double b = 1.0*diff[i]/2;

        if((a == diff[i+1]) || (b == diff[i+1])){
            // cout<<a<<" "<<b<<endl;
        }
        else{
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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