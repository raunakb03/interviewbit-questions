#include<bits/stdc++.h>
using namespace std;

// return the min number of jumps required to reach at the end position
int jump(vector<int> &A) {
    int n= A.size();
    int next_max=0, curr_max=0;
    int jumps=0;
    for(int i=0; i<n-1; i++){
        next_max= max(next_max, i+A[i]);
        if(i==curr_max){
            jumps++;
            curr_max= next_max;
        }
    }    
    if(curr_max<n-1) return -1;
    return jumps;
}
