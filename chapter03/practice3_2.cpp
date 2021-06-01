#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, v;
  cin >> N >> v;

  vector<int> array(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> array[i];
  }

  // count(array.begin(), array.end(), v) と同じ
  int count = 0;
  for (int i = 0; i < N; ++i)
  {
    if (array[i] == v)
    {
      ++count;
    }
  }

  cout << "count of " << v << ": " << count << endl;

  return 0;
}
