#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    if(n%2 != 0){
        cout<<-1<<endl;
    }
    else{
    //     // ll i=(n/2)+1;
        // while(i != (n+1)){
        //     cout<<i<<" ";
        //     i++;
        // }
        // i = 1;
        // while(i != ((n/2)+1)){
        //     cout<<i<<" ";
        //     i++;
        // }
        for (int i = n; i>0; i--)
        {
            cout<<i<<" ";
        }
        cout<<endl;
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