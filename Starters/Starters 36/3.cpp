#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll x,y,z;
    cin>>x>>y>>z;

    if(z%x == 0 && z%y== 0){
        cout<<"ANY\n";
    }
    else if(z%x == 0){
        cout<<"CHICKEN\n";
    }
    else if(z%y == 0){
        cout<<"DUCK\n";
    }
    else{
        cout<<"NONE\n";
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
//    solve();
   return 0;
}