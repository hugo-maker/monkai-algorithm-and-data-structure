#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1 << 29;

template<class T>
void chmax(T & a, T b)
{
  if (a < b)
  {
    a = b;
  }
}

int main()
{
  string S, T;
  cin >> S >> T;

  vector<vector<int>> dp(3100, vector<int>(3100, INF));
  for (int i = 0; i < S.size(); ++i)
  {
    for (int j = 0; j < T.size(); ++j)
    {
      if (S[i] == T[j])
      {
        chmax(dp[i + 1][j + 1], dp[i][j] + 1);
      }
      chmax(dp[i + 1][j + 1], dp[i + 1][j]);
      chmax(dp[i + 1][j + 1], dp[i][j + 1]);
    }
  }

  string res = "";
  int i = (int)S.size();
  int j = (int)T.size();
  while (i > 0 && j > 0)
  {
    // (i - 1, j) -> (i, j) と更新されていた場合
    if (dp[i][j] == dp[i - 1][j])
    {
      // DPの遷移を遡る
      --i;
    }
    // (i, j - 1) -> (i, j) と更新されていた場合
    else if (dp[i][j] == dp[i][j - 1])
    {
      // DPの遷移を遡る
      --j;
    }
    // (i - 1, j - 1) -> (i, j) と更新されていた場合
    else
    {
      res = S[i - 1] + res;
      --i;
      --j;
    }
  }

  cout << res << endl;

  return 0;
}
