#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int ans[t];
    int m=0;
    while(t != 0){
        int len_array;
        cin>>len_array;

        int arr[len_array];
        int sum = 0;
        for(int i=0;i<len_array;i++){
            int j=i+1;
            if(j == len_array){
                break;
            }
            int product = arr[i]*arr[j];
            sum += product;
        }
        if(sum %2 != 0){//lovely permutation
            int *new_arr = new int[len_array];
            
        }
        else{
            ans[m] = -1;
        }
    }

    for(int ind = 0;ind<m;ind++){
        cout<<ans[ind]<<endl;
    }
    return 0;
}