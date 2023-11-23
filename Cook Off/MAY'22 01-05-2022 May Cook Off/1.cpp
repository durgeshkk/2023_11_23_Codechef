#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,m,k;
    cin>>n>>m>>k;
    
    if(n+m <= k){
        cout<<2<<endl;
    }
    else if(n <= k){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
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