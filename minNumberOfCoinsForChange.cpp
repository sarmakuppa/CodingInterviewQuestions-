#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int amount, vector<int> denoms) {
  // Write your code here.

    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      
        for (int coin: denoms) {
          
            if (i - coin >= 0)
                dp[i] = min(dp[i - coin] + 1, dp[i]);
        }
    }

  
    return (dp[amount] > amount) ? -1 : dp[amount];
}
