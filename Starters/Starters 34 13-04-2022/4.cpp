#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    vector<ll> v;
    ll p_count=0;
    ll n_count=0;
    for(int i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
        if(ele>0){
            p_count++;
        }
        else if(ele<0){
            n_count++;
        }
    }

    ll p_ans = (p_count*(p_count-1))/2;
    ll n_ans = (n_count*(n_count-1))/2;

    ll ans = p_ans+n_ans;
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}