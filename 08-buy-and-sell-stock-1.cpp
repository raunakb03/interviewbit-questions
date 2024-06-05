#include<bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &A) {
    int n= A.size();
    int profit=0;
    int buyPrice=-1;
    for(auto c : A){
        if(buyPrice==-1){
            buyPrice= c;
            continue;
        }
        profit= max(profit, c-buyPrice);
        buyPrice= min(c, buyPrice);
    }
    return profit;
}
