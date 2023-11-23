#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    string s;
    cin>>s;

    ll count_1 = 0;
    ll count_0 = 0;
    
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '1'){
            count_1++;
        }
        else{
            count_0++;
        }
    }
    
    ll L=1,R=n;
    ll req_1 = n/2;
    if(n%2 == 0){
        if(req_1 == count_1){
            cout<<"YES\n";
            cout<<L<<" "<<R<<endl;
            return;
        }
        else{
            ll diff = req_1 - count_1;
            if(diff>0){
                string new_s="";
                while(diff != 0){
                    new_s+="0";
                    diff--;
                }
                ll found = s.find(new_s);
                L = found+1;
                R = L+(req_1-count_1)-1;
                if(found != string::npos){
                    cout<<"YES\n";
                    cout<<L<<" "<<R<<endl;
                    return;
                }
                cout<<"NO\n";
            }
            else{
                string new_s="";
                while(diff != 0){
                    new_s+="1";
                    diff++;
                }
                ll found = s.find(new_s);
                L = found+1;
                R = L+(req_1-count_1)+1;
                if(found != string::npos){
                    cout<<"YES\n";
                    cout<<L<<" "<<R<<endl;
                    return;
                }
                cout<<"NO\n";
            }
        }
    }
    else{
        cout<<"NO\n";
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