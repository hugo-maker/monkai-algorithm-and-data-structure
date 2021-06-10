#include <iostream>
#include <vector>
using namespace std;

template<class T>
bool chmax(T & a, T b)
{
  if (a < b)
  {
    a = b;
  }
}
template<class T>
bool chmin(T & a, T b)
{
  if (a > b)
  {
    a = b;
  }
}

const int INF = 1 << 29;

int main()
{
  int N, W;
  cin >> N >> W;
  vector<int> a(N), m(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> a[i] >> m[i];
  }

  vector<int> dp(N + 1, vector<int>(W + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j <= W; ++j)
    {
      if (dp[i][j] < INF)
      {
        chmin(dp[i + 1][j], 0);
      }
      if (j + a[i] <= W && dp[i + 1][j] < m[i])
      {
        chmin(dp[i + 1][j + a[i]], dp[i + 1][j] + 1);
      }
    }
  }

  if (dp[N][W] < INF)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

}
