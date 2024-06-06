#include<bits/stdc++.h>
using namespace std;



// tabulation not correct start from index 1 and go on
bool f(string& s, map<string,bool>& mp, int ind, vector<int>& dp){
    if(ind>=s.size()) return true;
    if(dp[ind]!=-1) return dp[ind];
    for(int i=ind; i<s.size(); i++){
        string st= s.substr(ind, i-ind+1);
        if(mp[st]){
            bool ans= f(s, mp, i+1, dp);
            if(ans==true) return dp[ind]= true;
        }
    }
    return dp[ind]= false;
}
// dp[i] -> whether can make it till this index or not
int wordBreak(string A, vector<string> &B) {
    map<string, bool> mp;
    int n= A.size();
    vector<bool> dp(n+1, false);
    dp[n]= true;
    for(auto c : B) mp[c]= true;
    for(int i=n-1; i>=0; i--){
        for(int j=i; j<n; j++){
            string st= A.substr(i, j-i+1);
            if(mp[st]){
                dp[i]= dp[j+1];
            }
        }
    }
    return dp[0];
}
