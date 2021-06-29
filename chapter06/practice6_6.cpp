// Atcoder Beginner Contest 026
// D 高橋君ボール 1 号
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

static const double pi = 3.141592653589793;
double A, B, C;

double f(double t)
{
  return A * t + B * sin(C * t * pi);
}

int main()
{
  cin >> A >> B >> C;

  double left = -1000.0;
  double right = 1000.0;

  for (int i = 0; i < 10000; ++i)
  {
    double mid = (left + right) / 2.0;
    if (f(mid) < 100.0)
    {
      left = mid;
    }
    else
    {
      right = mid;
    }
  }

  cout << setprecision(20) << left << endl;

  return 0;
}
