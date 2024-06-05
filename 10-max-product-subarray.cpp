#include<bits/stdc++.h>
using namespace std;

// contingous subarray in the array which has the maximum product
int maxProduct(const vector<int> &A) {
    int n= A.size();
    int ans=*min_element(A.begin(), A.end());
    int prod=1;
    for(auto c : A){
        prod*= c;
        ans= max(ans, prod);
        if(prod==0) prod=1;
    }
    prod=1;
    for(int i=n-1; i>=0; i--){
        prod*=A[i];
        ans= max(ans, prod);
        if(prod==0) prod=1;
    }
    return ans; 
}
