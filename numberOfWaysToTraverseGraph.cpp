// First version

using namespace std;

int numberOfWaysToTraverseGraph(int width, int height) {
  // Write your code here.

    vector< vector<int> > dp(width, 
                  vector<int>(height, 0));

    for (int i = 0; i < height; i++)  dp[0][i] = 1;

    for (int i = 0; i < width; i++)  dp[i][0] = 1;

    for (int i = 1; i < width; i++)  {
        for (int j = 1; j < height; j++)  {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[width-1][height-1];
}



// Second Version

using namespace std;

int numberOfWaysToTraverseGraph(int width, int height) {
  // Write your code here.
    vector<int>  dp(height, 0);

    for (int i = 0; i < height; i++)  dp[i] = 1;

    for (int i = 1; i < width; i++)  {
        for (int j = 1; j < height; j++)  {
            dp[j] = dp[j] + dp[j - 1];
        }
    }

    return dp[height-1];
}


/*
 * Can you come up with a O(rows+ cols) time and O(1) space algorithm?
 *
 *
 * Yes, this is possible! To achieve O(rows+cols} time and O(1) space, 
 * we move away from Dynamic Programming and use Combinatorics. 
 * 
 * The Mathematical Insight:
 * ========================
 * 
 * To get from the top-left (0,0) to the bottom-right (R-1,C-1): 
 * You must make exactly (R-1) moves Down.You must make exactly (C-1) moves
 * Right.The total number of moves is always (R-1)+(C-1)=R+C-2. The problem 
 * is now:  "In a sequence of N total moves, in how many ways can we choose
 * which ones are 'Down'?" 
 * 
 * This is the formula for Combinations (nCr)
 * n = (rows - 1) + (cols - 1)
 * k = cols - 1 (or rows - 1)
 */


using namespace std;

int numberOfWaysToTraverseGraph(int width, int height) {
  // Write your code here.

    int n = width + height - 2;
    int k = (width < height) ? width - 1 : height - 1;

    int result = 1;

    // Calculating nCr iteratively:
    // res = (n * (n-1) * ... * (n-k+1)) / (k * (k-1) * ... * 1)
    for (int i = 1; i <= k; i++) {
        result = result * (n - k + i) / i;
    }
    
    return result;
}
