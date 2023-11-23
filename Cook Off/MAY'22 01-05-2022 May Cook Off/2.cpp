#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll x,y;
    cin>>x>>y;

    if(10*y <= 100*x){
        cout<<"Cloth\n";
    }
    else{
        cout<<"Disposable\n";
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