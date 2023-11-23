#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;
   cin >> t;
   while (t--)
   {
        ll left,right;
        cin>>left>>right;

        ll dk = 0;
        if(left != 0){
            set<ll> ok;
            for(ll i=left;i<right+1;i++){
                for(ll j = i;j<right+1;++j){
                    if((i+j) == (i^j)){
                        ok.insert(i^j);
                    }
                }
            }

            ll sz = ok.size();
            dk = sz;
        }else{
            bitset<80> t(right);
            ll ele = 0,index = -1;
            for(ll j = 80;j>=0;--j){
                if(t[j] != 1){
                }else{
                    ++ele;
                    index = j;
                    break;
                }
            }

            dk = 1;
            for(ll i = 0;i<=index;++i){
                dk *= 2;
            }
        }
        cout<<dk<<endl;
    }
    return 0;
}