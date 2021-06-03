// atcoder abc c
// 755
#include <iostream>
using namespace std;

bool solve(int num)
{
  int dig = 0;
  bool has_3 = false;
  bool has_5 = false;
  bool has_7 = false;
  while (num)
  {
    dig = num % 10;
    if (dig == 3)
    {
      has_3 = true;
    }
    else if (dig == 5)
    {
      has_5 = true;
    }
    else if (dig == 7)
    {
      has_7 = true;
    }
    else
    {
      return false;
    }

    num = num / 10;
  }

  if (has_3 && has_5 && has_7)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int N;
  cin >> N;
  int result = 0;

  if (N >= 357)
  {
    for (int i = 357; i <= N; i += 2)
    {
      if (solve(i))
      {
        ++result;
      }
    }
  }

  cout << result << endl;

  return 0;
}
