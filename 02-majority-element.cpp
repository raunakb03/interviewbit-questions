#include <bits/stdc++.h>
using namespace std;

int majorityElement(const vector<int> &A) {
  int n = A.size();
  int ele = -1, cnt = 0;
  for (auto c : A) {
    if (ele == -1) {
      ele = c;
      cnt = 1;
    } else if (ele == c) {
      cnt++;
    } else {
      cnt--;
      if (cnt == 0)
        ele = -1;
    }
  }
  return ele;
}
