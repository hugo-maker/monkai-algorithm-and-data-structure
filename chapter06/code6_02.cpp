#include <iostream>
using namespace std;

// x が条件を満たすか否か
bool P(intx)
{
}

// P(x) = true となる最小の整数 x を返す
int binary_search()
{
  // P(left) = false, P(right) = true となるように
  int left, right;

  while (right - left > 1)
  {
    int mid = left + (right - left) / 2;
    if (P(mid))
    {
      right = mid;
    }
    else
    {
      left = mid;
    }
  }

  return right;
}
