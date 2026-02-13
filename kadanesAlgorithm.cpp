#include <bits/stdc++.h>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
  // Write your code here.
    int maxSum = array[0];
    int maxSoFar = array[0];

    for (int i = 1; i < array.size(); i++) {
        int x = array[i];
        maxSoFar = max(x, maxSoFar + x);
        maxSum = max(maxSum, maxSoFar);
    }
  
    return maxSum;
}
