#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll a = 0,b = 0,i = 0;
    for(i;i<n;++i){
        if(s[i] == 'A'){++a;}
        else{break;}
    }

    for(i;i<n;i++){
        if(s[i] == 'B'){
            ll ele = 0;
            while(i < n and s[i] == 'B'){
                ++ele;++i;
            }
            b += (ele-1);
            --i;
        }else{
            ll ele = 0;
            while(i < n and s[i] == 'A'){
                ++ele;++i;
            }
            a += (ele-1);
            --i;
        }
    }
    cout<<a<<" "<<b<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}