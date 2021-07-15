// Atcoder Beginner Contest 131
// D - Megalomania
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<pair<int, int>> v(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> v[i].second >> v[i].first;
  }

  sort(v.begin(), v.end());

  int now = 0;
  for (int i = 0; i < N; ++i)
  {
    now += v[i].second;
    if (now > v[i].first)
    {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
