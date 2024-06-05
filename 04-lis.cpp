#include<bits/stdc++.h>
using namespace std;

int lis(const vector<int> &A) {
    int n= A.size();
    int ans=0;
    vector<int> temp;
    for(auto c : A){
        auto ind= lower_bound(temp.begin(), temp.end(), c);
        if(ind!=temp.end()){
            auto index= ind-temp.begin();
            temp[index]= c;
        } else {
            temp.push_back(c);
        } 
    }
    return temp.size();
}
