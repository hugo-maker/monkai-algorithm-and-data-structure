// AtCoder ABC023
// D 射撃王
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;
  vector<long long> h(N), s(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> h[i] >> s[i];
  }

  long long left = 0;
  long long right = INF;
  while (right - left > 1)
  {
    long long mid = (left + right) / 2;

    bool ok = true;
    // 各風船を割るまでの時間制限
    vector<long long> t(N, 0);
    for (int i = 0; i < N; ++i)
    {
      // mid が初期高度より低い場合はその時点でfalse
      if (mid < h[i])
      {
        ok = false;
      }
      else
      {
        t[i] = (mid - h[i]) / s[i];
      }
    }
    // 時間制限が迫っている順にソート
    sort(t.begin(), t.end());
    for (int i = 0; i < N; ++i)
    {
      if (t[i] < i)
      {
        // 時間切れ発生
        ok = false;
      }
    }

    if (ok)
    {
      right = mid;
    }
    else
    {
      left = mid;
    }
  }

  cout << right << endl;

  return 0;
}
