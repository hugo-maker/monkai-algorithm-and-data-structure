#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  long long N, M;
  cin >> N >> M;
  vector<long long> a(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> a[i];
  }

  a.push_back(0);
  vector<long long> S;
  for (int i = 0; i < a.size(); ++i)
  {
    for (int j = 0; j < a.size(); ++j)
    {
      S.push_back(a[i] + a[j]);
    }
  }
  sort(S.begin(), S.end());

  long long ans = 0;
  for (long long e : S)
  {
    auto iter = upper_bound(S.begin(), S.end(), M - e);
    if (iter == S.begin())
    {
      continue;
    }
    --iter;
    ans = max(ans, e + *iter);
  }

  cout << ans << endl;

  return 0;
}
