#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

template<class T>
void chmax(T & a, T b)
{
  if (a < b)
  {
    a = b;
  }
}

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

  vector<vector<double>> f(N + 1, vector<double>(N + 1));
  for (int i = 1; i <= N; ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      double sum = 0;
      for (int k = j; k < i; ++k)
      {
        sum += a[k];
      }
      f[j][i] = sum / (i - j);
    }
  }

  vector<vector<double>> dp(N + 1, vector<double>(M + 1, -INF));
  dp[0][0] = 0;
  for (int i = 0; i <= N; ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      for (int k = 1; k <= M; ++k)
      {
        chmax(dp[i][k], dp[j][k - 1] + f[j][i]);
      }
    }
  }

  double res = -INF;
  for (int m = 0; m <= M; ++m)
  {
    chmax(res, dp[N][m]);
  }

  cout << fixed << setprecision(10) << res << endl;
}
