#include<bits/stdc++.h>
#define ll int
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll a,b,k;
    cin>>a>>b>>k;

    if(a > b){swap(a,b);}
    if(__gcd(a,b) == 1){
        if(k == 1){
            cout<<(a+1)<<endl;
        }else{
            cout<<(2)<<endl;
        }
    }else if(a == b){
        cout<<(2*a)<<endl;
    }else{
        ll ans = (a+b);
        while(k){
            b = __gcd(a,b);
            ll ele = __gcd(a,b);
            a /= ele;a *= b;
            // a = (b*a)/__gcd(b,a);
            if(a > b){swap(a,b);}
            ans = min(ans,a+b);
            --k;
            if(__gcd(a,b) == 1){break;}
            else if(a == b){
                cout<<(2*a)<<endl;return;
            }
        }
        if(k == 1){
            cout<<(a+1)<<endl;
        }else if(k > 1){
            cout<<(2)<<endl;
        }else{
            cout<<(ans)<<endl;
        }
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}