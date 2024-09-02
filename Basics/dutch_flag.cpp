/*

Move all the negative number to the left side of the array ---> not sorted

*/

#include <bits/stdc++.h>
using namespace std;

void solve(int arr[],int n){
    int s=0;int e=n-1;
    while(s<e){
        if(arr[s]<0){
            s++;
        }
        else if(arr[e]>0){
            e--;
        }
        else{
            swap(arr[s],arr[e]);
        }
    }
}

int main(){
    int arr[8]={1,-100,2,-3,4,-5,6,-10};
    solve(arr,8);
    
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
}