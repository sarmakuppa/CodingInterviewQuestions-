#include <bits/stdc++.h>
using namespace std;

vector<int> missingNumbers(vector<int> nums) {
  // Write your code here.
    int n = nums.size();

    //cout << "size = " << n << endl;

    vector<int> missingNos;

    nums.push_back(1);
    nums.push_back(1);

    for (int i = 0; i < n; i++) {
            nums[ abs(nums[i] ) - 1 ] *= -1;
    }

    for (int i = 0; i < n + 2; i++) {

        //cout << nums[i] << "  ";
        if (nums[i] > 0)  missingNos.push_back(i+1);
    }

  
    return missingNos;
}
