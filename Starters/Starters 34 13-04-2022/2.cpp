#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    if((c<a) || (d<b)){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        cout<<"POSSIBLE\n";
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