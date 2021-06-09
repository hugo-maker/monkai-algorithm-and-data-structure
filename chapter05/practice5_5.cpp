#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, W;
  cin >> N >> W;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> a[i];
  }

  vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
  dp[0][0] = true;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j <= W; ++j)
    {
      if (dp[i][j])
      {
        dp[i + 1][j] = true;
      }
      if (dp[i + 1][j] && j + a[i] <= W)
      {
        dp[i + 1][j + a[i]] = true;
      }
    }
  }

  if (dp[N][W])
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
