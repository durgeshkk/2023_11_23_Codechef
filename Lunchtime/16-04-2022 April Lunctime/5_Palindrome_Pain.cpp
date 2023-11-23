#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll x,y;
    cin>>x>>y;

    if(x%2 != 0 && y%2 != 0){
        cout<<-1<<endl;
        return;
    }

    if(x == 1 || y== 1){
        cout<<-1<<endl;
        return;
    }

    if(x%2 == 0 && y%2 == 0){
        string s1="";
        string s2="";

        ll i=0;
        while(i < (x/2)){
            s1+='a';
            i++;
        }

        ll j=0;
        while(j<(y)){
            s1 += 'b';
            j++;
        }

        while(i < (x)){
            s1+='a';
            i++;
        }

        i=0;
        while(i < (y/2)){
            s2+='b';
            i++;
        }

        j=0;
        while(j<(x)){
            s2 +='a';
            j++;
        }

        while(i < (y)){
            s2+='b';
            i++;
        }
        cout<<s1<<endl;
        cout<<s2<<endl;
    }

    else if(x%2 == 0){
        string s1="";
        string s2="";

        ll i=0;
        while(i < (x/2)){
            s1+='a';
            i++;
        }

        ll j=0;
        while(j<(y)){
            s1 += 'b';
            j++;
        }

        while(i < (x)){
            s1+='a';
            i++;
        }

        // Now for s2
        s2 = s1;
        swap(s2[0],s2[((x+y)/2) - 1]);
        swap(s2[x+y-1],s2[((x+y)/2) - 1]);

        cout<<s1<<endl;
        cout<<s2<<endl;
    }
    else if(y%2 == 0){
        string s1="";
        string s2="";

        ll i=0;
        while(i < (y/2)){
            s1+='b';
            i++;
        }

        ll j=0;
        while(j<(x)){
            s1 += 'a';
            j++;
        }

        while(i < (y)){
            s1+='b';
            i++;
        }

        // Now for s2
        s2 = s1;
        swap(s2[0],s2[((x+y)/2) - 1]);
        swap(s2[x+y-1],s2[((x+y)/2) - 1]);

        cout<<s1<<endl;
        cout<<s2<<endl;
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