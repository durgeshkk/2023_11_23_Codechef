#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    if(n%3 == 0){
        cout<<"NORMAL\n";
    }
    else if(n%3 == 1){
        cout<<"HUGE\n";
    }
    else{
        cout<<"SMALL\n";
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
   return 0;
}