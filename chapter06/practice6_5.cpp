// Atcoder Regular Contest 037
// C 億マス計算
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, K;
vector<long long> a, b;

bool check(long long x)
{
  long long count = 0;
  for (int i = 0; i < N; ++i)
  {
    count += upper_bound(b.begin(), b.end(), x / a[i]) - b.begin();
  }

  return count >= K;
}

int main()
{
  cin >> N >> K;
  a.resize(N);
  b.resize(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> a[i];
  }
  for (int i = 0; i < N; ++i)
  {
    cin >> b[i];
  }

  sort(b.begin(), b.end());

  long long ng = 0;
  long long ok = 1e+18;
  while (ok - ng > 1)
  {
    long long mid = (ng + ok) / 2;
    if (check(mid))
    {
      ok = mid;
    }
    else
    {
      ng = mid;
    }
  }

  cout << ok << endl;

  return 0;
}
