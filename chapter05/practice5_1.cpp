// atcoder educational dp contest
// c vacation
#include <iostream>
#include <vector>
using namespace std;

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
  int N;
  cin >> N;
  vector<vector<int>> v(N, vector<int>(3));
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      cin >> v[i][j];
    }
  }

  vector<vector<int>> dp(N + 1, vector<int>(3));

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      for (int k = 0; k < 3; ++k)
      {
        if (j == k)
        {
          continue;
        }
        chmax(dp[i + 1][k], dp[i][j] + v[i][k]);
      }
    }
  }

  int result = 0;
  for (int j = 0; j < 3; ++j)
  {
    chmax(result, dp[N][j]);
  }

  cout << result << endl;

  return 0;
}
