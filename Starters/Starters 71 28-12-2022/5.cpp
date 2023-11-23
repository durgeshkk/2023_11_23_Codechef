#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
ll lcs(string &X, string &Y, ll m, ll n)
{
    ll L[m+1][n+1];
    for (ll i = 0; i <= m; i++){
        for (ll j = 0; j <= n; j++){
            if (i == 0 || j == 0){
                L[i][j] = 0;
            }else if (X[i - 1] == Y[j - 1]){
                L[i][j] = L[i - 1][j - 1] + 1;
            }else{
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    return L[m][n];
}


void solve()
{
 
    ll n;cin>>n;
    string s;cin>>s;

    string a=s;
    string b=s;
    reverse(b.begin(),b.end());

    ll mx = lcs(a,b,a.size(),b.size());

    /*
    for(ll i=0;i<n;i++){
        // Check for LCS now!!
        mx = max(mx,val);
        a += s[i];
        b.pop_back();
    }*/
    cout<<mx/2<<endl;
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