using namespace std;

int majorityElement(vector<int> array) {
  // Write your code here.

  int number;
  int count = 0;

  for (int x: array) {
    if (count == 0) {
      number = x;
      count++;
      continue;
    }

    if ( x != number ) count--;
    else count++;
  }
  
  return number;
}
