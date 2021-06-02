#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> F(N);
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i < N; ++i)
  {
    F[i] = F[i - 1] + F[i - 2];
    cout << i << " 項目: " << F[i] << endl;
  }

  return 0;
}
