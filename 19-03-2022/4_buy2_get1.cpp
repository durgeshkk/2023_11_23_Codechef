#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int ans[t];
    int i=0;
    while(t != 0){
        int items,price,amt;
        cin>>items>>price;

        int free_item = items/3;
        amt = (items-free_item)*price;
        ans[i] = amt;
        
        i++;
        t--;
    }

    for(int ind = 0;ind<i;ind++){
        cout<<ans[ind]<<endl;
    }
    return 0;
}