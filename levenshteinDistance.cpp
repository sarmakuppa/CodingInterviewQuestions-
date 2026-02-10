using namespace std;
#include <bits/stdc++.h>

int levenshteinDistance(string str1, string str2) {
  // Write your code here.
    int rows = str1.length();
    int cols = str2.length();

    if (rows == 0) return cols;
    if (cols == 0) return rows;

    vector< vector<int> > dp(rows + 1, 
                  vector<int>(cols + 1, 0));

    for (int i = 0; i <= cols; i++)  dp[0][i] = i;

    for (int i = 0; i <= rows; i++)  dp[i][0] = i;

    for (int i = 1; i <= rows; i++)  {
        for (int j = 1; j <= cols; j++)  {
            if ( str1[i - 1] == str2[j - 1] )
                dp[i][j] = dp[i - 1][j - 1];
            else {
                int lev1 = dp[i-1][j];
                int lev2 = dp[i][j-1];
                int lev3 = dp[i-1][j-1];

                int temp = min(lev1, lev2);
                dp[i][j] = 1 + min(temp, lev3);
            }
        }
    }



    // for (int j = 1; j <= cols; j++)  {
    //     for (int i = 1; i <= rows; i++)  {
    //         if ( str1[i-1] == str2[j-1] )
    //             dp[i][j] = dp[i - 1][j - 1];
    //         else {
    //             int lev1 = dp[i-1][j];
    //             int lev2 = dp[i][j-1];
    //             int lev3 = dp[i-1][j-1];

    //             int temp = min(lev1, lev2);
    //             dp[i][j] = 1 + min(temp, lev3);
    //         }
    //     }
    // }

  

    // for (int i = 1; i <= rows; i++)  {
    //     for (int j = 1; j <= cols; j++)  {
    //         cout << setw(4) << dp[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    
    

    return dp[rows][cols];
}
