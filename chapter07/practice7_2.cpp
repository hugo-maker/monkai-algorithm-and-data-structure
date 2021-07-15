// Atcoder Regular Contest 092
// C - 2D Plane 2N Points

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<pair<int, int>> red(N);
  vector<pair<int, int>> blue(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> red[i].first >> red[i].second;
  }
  for (int i = 0; i < N; ++i)
  {
    cin >> blue[i].first >> blue[i].second;
  }

  sort(blue.begin(), blue.end());

  vector<bool> used(N, false);

  int cnt = 0;
  for (int i = 0; i < N; ++i)
  {
    int maxy = -1;
    int maxid = -1;
    for (int j = 0; j < N; ++j)
    {
      if (used[j])
      {
        continue;
      }

      if (red[j].first >= blue[i].first)
      {
        continue;
      }
      if (red[j].second >= blue[i].second)
      {
        continue;
      }

      if (maxy < red[j].second)
      {
        maxy = red[j].second;
        maxid = j;
      }
    }

    if (maxid == -1)
    {
      continue;
    }

    ++cnt;
    used[maxid] = true;
  }

  cout << cnt << endl;
  return 0;
}
