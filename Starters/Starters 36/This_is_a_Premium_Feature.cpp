#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    
    if(n%2 != 0){
        cout<<1<<endl;
    }
    else{
        ll count=0;
        while(n%4 == 0){
            count=1;
            n /= 4;
        }
        if(n%2 == 0){
            cout<<-1<<endl;
        }
        else if(n == 1){
            cout<<count<<endl;
        }
        else{
            cout<<count+1<<endl;
        }
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