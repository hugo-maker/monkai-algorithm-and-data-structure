#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> array(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> array[i];
  }

  sort(array.begin(), array.end());

  cout << array[N - 1] - array[0] << endl;

  return 0;
}
