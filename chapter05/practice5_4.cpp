#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1 << 29;

int main()
{
  int N, W, k;
  cin >> N >> W >> k;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> a[i];
  }

  vector<vector<int>> dp(N + 1, vector<int>(W + 1, INF));

  dp[0][0] = 0;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j <= W; ++j)
    {
      // a[i] を選ばない
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

      // a[i] を選ぶ
      if (j >= a[i])
      {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - a[i]] + 1);
      }
    }
  }

  if (dp[N][W] <= k)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
