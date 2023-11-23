#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int ans[t];
    int i=0;
    while(t != 0){
        int coins;
        cin>>coins;

        if(coins%5 == 0){
            int count=1;
            if(coins%10 == 0){
                coins = coins / 10;
                ans[i] = coins;
            }
            else{
                coins = coins / 10;
                ans[i] = coins+1;
            }
        }

        else{
            ans[i] = -1;
        }
        i++;
        t--;
    }

    for(int ind = 0;ind<i;ind++){
        cout<<ans[ind]<<endl;
    }
    return 0;
}