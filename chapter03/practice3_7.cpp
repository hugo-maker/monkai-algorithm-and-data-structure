// atcoder abc 045 c
// たくさんの数式
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S;
  cin >> S;
  int N = S.size();

  long long result = 0;

  for (int bit = 0; bit < (1 << (N - 1)); ++bit)
  {
    long long temp = 0;
    for (int i = 0; i < N - 1; ++i)
    {
      temp *= 10;
      temp += S[i] - '0';

      if (bit & (1 << i))
      {
        result += temp;
        temp = 0;
      }
    }

    temp *= 10;
    temp += S.back() - '0';
    result += temp;
  }

  cout << result << endl;

  return 0;
}
