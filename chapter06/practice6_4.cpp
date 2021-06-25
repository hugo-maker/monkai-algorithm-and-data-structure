#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1LL << 60;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<long long> a(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  long long left = 0;
  long long right = INF;

  while (right - left > 1)
  {
    long long x = (left + right) / 2;

    int count = 1;
    int prev = 0;
    for (int i = 0; i < N; ++i)
    {
      if (a[i] - a[prev] >= x)
      {
        ++count;
        prev = i;
      }
    }

    if (count >= M)
    {
      left = x;
    }
    else
    {
      right = x;
    }
  }

  cout << left << endl;

  return 0;
}
