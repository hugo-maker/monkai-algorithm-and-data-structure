#include <iostream>
using namespace std;

int tribo(int N)
{
  if (N == 0 || N == 1)
  {
    return 0;
  }
  else if (N == 2)
  {
    return 1;
  }

  int result = tribo(N - 1) + tribo(N - 2) + tribo(N - 3);

  return result;
}

int main()
{
  int N;
  cin >> N;
  cout << tribo(N) << endl;

  return 0;
}
