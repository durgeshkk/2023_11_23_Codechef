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
    vector<ll> v,odd,even;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);

       if(ele%2){
           odd.push_back(ele);
       }
       else{
           even.push_back(ele);
       }
    }

    ll odd_sum = accumulate(odd.begin(),odd.end(),0);
    ll even_sum = accumulate(even.begin(),even.end(),0);

    // if() 
    ll oans = odd_sum/odd.size();
    ll eans = even_sum/even.size();

    if(v.size() == 2){
        cout<<"YES\n";
        return;
    }

    if((odd_sum%(n/2) != 0) || (even_sum%(n/2) != 0) ||(oans%2 == 0) || (eans%2 != 0)){
        cout<<"NO\n";
        return;
    }

    ll o_req = odd_sum*2/n;
    ll e_req = even_sum*2/n;

    vector<ll> o_inc((n/2)-1);
    vector<ll> e_inc((n/2)-1);

    for(ll i=0;i<n/2;i++){
        o_inc[i] = (odd[i] - o_req);
    }

    for(ll i=0;i<n/2;i++){
        cout<<o_inc[i]<<" ";
    }
    cout<<endl;
    
    for(ll i=0;i<n/2;i++){
        e_inc[i] = (even[i] - e_req);
    }
    
    for(ll i=0;i<n/2;i++){
        cout<<e_inc[i]<<" ";
    }
    cout<<endl;
    

    while(o_inc.back() == 0){
        o_inc.pop_back();
    }
    
    while(e_inc.back() == 0){
        e_inc.pop_back();
    }

    if(is_sorted(o_inc.begin(),o_inc.end()) && is_sorted(e_inc.begin(),e_inc.end())){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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