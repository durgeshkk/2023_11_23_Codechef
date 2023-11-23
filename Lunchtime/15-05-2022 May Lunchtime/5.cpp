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
 /*
    ll n;
    cin>>n;

    ll m;
    cin>>m;
    map<ll,ll> mp;

    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
       mp[v[i]] = (v[i]%m);
    }

    int diff[n];
    sort(v.begin(),v.end());
    // reverse(v.begin(),v.end());
// /*
    ll a1 = v[0];
    int idx = -1;

    for(int i=0;i<n;i++){
        if(v[i] != v[0]){
            idx = i;
            break;
        }
    }
    ll a2 = v[idx];
    
    ll t2 = 0;
    ll ans1 = a1 + a1;
    ll ans2 = a1 + a2;

    ll v1 = mp[v[0]];
    ll v2 = mp[v[idx]];
    
    ll b1 = (v1-v2)%m;
    ll b2 = (v2-v1)%m;
    
    if(b2 < 0){
        b2 = m-(abs(b2)%m);
        // b2 = m+b2;
    }
    
    if(b1 > b2){
        t2 += b1;
    }
    else{
        t2 += b2;
    }

    ans2 += t2;

    if(ans1 > ans2){
        cout<<ans1<<endl;
    }
    else{
        cout<<ans2<<endl;
    }

// /*
    if(v[1] <= (v[0]-m)){
        a2 = v[1];
        cout<<ans<<endl;
        return;
    }
    for(ll j = 1;j<n;j++){
        ll a3 = v[j];
        ll v1 = mp[v[0]];
        ll v2 = mp[v[j]];

        ll t2 = a1 + a3;
        
        ll b1 = (v1-v2)%m;
        ll b2 = (v2-v1)%m;

        if(b2 < 0){
            b2 = m+b2;
        }

        if(b1 > b2){
            t2 += b1;
        }
        else{
            t2 += b2;
        }
        // if(m1 > m2){
        //     t2 += (m1);
        // }
        // else{
        //     t2 += (m2);
        // }
*/
        
        // cout<<ans<<endl;
    // }
/*
    ll idx = 0;
    ll mn = 0;
    for(int i=0;i<n;i++){
        ll t = (v[i]-v[n-1]);
        if(t < 0){
            diff[i] = m-(abs(t)%m);
        }
        else{
            diff[i] = (t%m);
        }

        if(diff[i] > mn){
            mn = diff[i];
            idx = i;
        }
    }

    ll ans = diff[idx]+v[idx]+v[n-1];
    cout<<ans<<endl;*/
    ll n,m;
    cin>>n>>m;

    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>v[i].second;
        v[i].first = v[i].second % m;
    }

    sort(v.begin(), v.end());

    ll ans = LLONG_MIN;
    for (ll i = 0; i < n; i++){
        ans = max(ans,2*v[i].second);
    }

    for (ll it=0; it<2; it++)
    {
        ll t = 0, mxf = LLONG_MIN;

        for (ll i = 0; i < n; i++){

            t = max(t,(v[i].first + v[i].second)+(mxf)+ it*m);
            
            if (!it || (((i+1)<n) && (v[i+1].first != v[i].first))){
                mxf = max(mxf,v[i].second-v[i].first);
            }
        }
        ans = max(ans,t);
        reverse(v.begin(), v.end());
    }
    cout <<ans<<endl;
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
   //solve();
   return 0;
}