#include <iostream>
#include <vector>
using namespace std;
const int INF = 20000000;

int main()
{
  int N;
  cin >> N;
  vector<int> array(N);

  for (int i = 0; i < N; ++i)
  {
    cin >> array[i];
  }

  int min = INF;
  for (int i = 0; i < N; ++i)
  {
    if (array[i] < min)
    {
      min = array[i];
    }
  }

  cout << "min = " << min << endl;

  return 0;
}
