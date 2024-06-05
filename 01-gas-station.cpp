#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(const vector<int> &a, const vector<int> &b) {
  // a contains the amount of gas in the station i
  // b contains the amount of gas required to travel from i to i+1
  int start = 0, deficit = 0, balance = 0, n = a.size();
  for (int i = 0; i < n; i++) {
    int curr = a[i] - b[i];
    balance += curr;
    if (balance < 0) {
      deficit += balance;
      start = i + 1;
      balance = 0;
    }
  }
  if (balance + deficit < 0)
    return -1;
  return start;
}
