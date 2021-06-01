#include <iostream>
#include <vector>
using namespace std;
const int INF = 20000000;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  vector<int> b(N);

  for (int i = 0; i < N; ++i)
  {
    cin >> a[i];
  }
  for (int i = 0; i < N; ++i)
  {
    cin >> b[i];
  }

  int min = INF;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if (a[i] + b[j] < K)
      {
        continue;
      }
      if (a[i] + b[j] < min)
      {
        min = a[i] + b[j];
      }
    }
  }

  cout << "min = " << min << endl;

  return 0;
}
