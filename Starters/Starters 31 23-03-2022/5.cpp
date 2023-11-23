#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    
    vector<int> v;

    while(t != 0){
        int n;
        cin>>n;
        int ans = 0;

        if(n % 2 == 0){
            ans = n/2;
        }
        else{
            ans = -(n+1)/2;
        }

        v.push_back(ans);
        t--;
    }

    for(auto it:v){
        cout<<it<<endl;
    }
    
    return 0;
}