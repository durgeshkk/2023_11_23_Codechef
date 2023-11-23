#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    vector<ll> v;
    ll count = 0;
    ll count_2 = 0;

    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
        
    }
    sort(v.begin(),v.end());

    for(ll i=0;i<n;i++){
        if(v[i] == 1){
            count += (n-i-1);
        }
        else if(v[i] == 2){
            count_2++;
        }
    }

    ll c2_ans = (count_2*(count_2-1)/2);
    cout<<count+c2_ans<<endl;
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
   return 0;
}