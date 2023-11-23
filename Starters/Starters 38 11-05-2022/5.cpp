#include<bits/stdc++.h>
#include <deque>
#define ll long long
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
   
   vector<ll> v1(n);
   for(ll i=0;i<n;i++){
      cin>>v1[i];
   }
   
   vector<ll> v2(n);
   for(ll i=0;i<n;i++){
      cin>>v2[i];
   }

   map<pair<ll,ll>,ll> m;
   ll count = 0;

    for(ll i=0;i<v1.size(); i++)
    {
        m[make_pair(v1[i],v2[i])]++;
    }

    map<pair<ll,ll>,bool> v;
    for (auto i : m)
    {
        ll dk11 = i.first.first;
        ll dk12 = i.first.second;
        ll dk2 = i.second;

        ll ans1=0,ans2=0;
        if (v[make_pair(dk11, dk12)] == true){
            continue;
        }

        if (dk11 == dk12){
            count = (count + (dk2*(dk2-1)/2));
        }
        else{
            ans1 = m[make_pair(dk11, dk12)];
            ans2 = m[make_pair(dk12, dk11)];
            count = count + (ans1*ans2);
            v[make_pair(dk12,dk11)]=true;
        }
    }
    cout<<count<<endl;
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