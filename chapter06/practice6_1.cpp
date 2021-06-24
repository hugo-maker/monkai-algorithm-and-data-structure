#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
  {
    cin >> a[i];
  }

  vector<int> b(N);
  copy(a.begin(), a.end(), b.begin());
  sort(b.begin(), b.end());

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if (a[i] == b[j])
      {
        cout << j << endl;
      }
    }
  }

  return 0;
}
