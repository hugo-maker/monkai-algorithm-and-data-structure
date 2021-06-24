// AtCoder Beginner Contest 077 C
// Snuke Festival
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N);

  for (int i = 0; i < N; ++i)
  {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i)
  {
    cin >> B[i];
  }
  for (int i = 0; i < N; ++i)
  {
    cin >> C[i];
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  long sum = 0;
  for (int j = 0; j < N; ++j)
  {
    long Aj = lower_bound(A.begin(), A.end(), B[j]) - A.begin();
    long Cj = C.end() - upper_bound(C.begin(), C.end(), B[j]);
    sum += Aj * Cj;
  }

  cout << sum << endl;

  return 0;
}
