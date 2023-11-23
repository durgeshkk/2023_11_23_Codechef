#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;

    ll days;
    if(n%k == 0){
        days = n/k;
    }
    else{
        days = (n/k)+1;
    }

    if(days>m){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
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