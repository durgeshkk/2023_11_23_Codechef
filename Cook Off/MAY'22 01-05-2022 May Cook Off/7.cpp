#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    // set<ll> s;
    vector<ll> v,a,b;
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
       b.push_back(ele);
       mp[ele]++;
    }

    if(mp.size() == 2){
        cout<<"NO\n";
        return;
    }
    
    sort(b.begin(),b.end());

    for(ll i=n/2;i<n;i++){
        a.push_back(b[i]);
    }
    for(ll i=0;i<n/2;i++){
        a.push_back(b[i]);
    }

    for(ll i=0;i<n;i++){
        if(a[i] == b[i]){
            cout<<"NO\n";
            return;
        }
    }
    
    cout<<"YES\n";
    for(ll i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    
    for(ll i=0;i<n;i++){
        cout<<a[i]<<" ";
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