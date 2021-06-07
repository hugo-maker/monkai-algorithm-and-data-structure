// atcoder typical dp contest
// a contest
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> a[i];
  }

  int W = 10000;
  vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
  dp[0][0] = true;

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j <= W; ++j)
    {
      if (!dp[i][j])
      {
        continue;
      }
      dp[i + 1][j] = true;
      if (j + a[i] <= W)
      {
        dp[i + 1][j + a[i]] = true;
      }
    }
  }

  int result = 0;
  for (int j = 0; j <= W; ++j)
  {
    if (dp[N][j])
    {
      ++result;
    }
  }

  cout << result << endl;
  return 0;
}
