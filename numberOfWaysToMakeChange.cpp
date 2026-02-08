#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  // Write your code here.

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int coin: denoms) {      
        for (int j = coin; j <= n; j++) {
            dp[j] += dp[j - coin];
        }
    }


    //for (int x: dp) cout << x << "  ";
  
    return dp[n];
}
