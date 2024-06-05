#include<bits/stdc++.h>
using namespace std;

// find the min number of candy required 
// such that child with higher rating must get higher candy
int candy(vector<int> &A) {
    int n= A.size();
    vector<int> v(n, 1);
    for(int i=1; i<n; i++){
        if(A[i]>A[i-1]){
            v[i]= 1+v[i-1];
        }
    }
    for(int i=n-2; i>=0; i--){
        if(A[i]>A[i+1]){
            v[i]= max(v[i], v[i+1]+1);
        }
    }
    int ans= accumulate(v.begin(), v.end(), 0);
    return ans;
}
