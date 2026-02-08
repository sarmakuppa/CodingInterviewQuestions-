#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
  // Write your code here.
    int n = array.size();
    if (n == 0) return 0;
    if (n == 1) return array[0];

    int second = array[0];
    int first = max(array[0], array[1]);

    for (int i = 2; i < n; i++)  {
        int sum = array[i] + second;

        int current = max(first, sum);


        second = first;
        first = current;        
    }
  
    return first;
}
