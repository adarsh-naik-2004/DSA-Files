/*
if ele == target ---> store the ans ---> see its left and right as per sorting
*/
#include <bits/stdc++.h>
using namespace std;

int firstindex(vector<int> arr,int target){
    int s=0;int e=arr.size()-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        int ele=arr[mid];
        if(ele==target){
            ans=mid;
            e=mid-1;
        }
        else if(target>ele){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}