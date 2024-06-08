#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pal;
vector<int> t;

bool isPalindrome(string& s, int i, int j){
    if(i>=s.size()) return true;
    if(pal[i][j]!=-1) return pal[i][j];
    while(i<j){
        if(s[i]!=s[j]) return pal[i][j]= false;
        i++, j--;
    }
    return pal[i][j]= true;
}

int minCut(string s) {
    int n= s.size();
    pal.resize(s.size()+1, vector<int>(s.size()+1, -1));
    t.resize(s.size()+1, 0);
    for(int i=n-1; i>=0; i--){
        int cost= 1e9;
        for(int j=i; j<s.size(); j++){
            if(isPalindrome(s, i, j)){
                cost= min(cost, 1+t[j+1]);
            }
        }
        t[i]= cost;
    }
    return t[0]-1;
}
