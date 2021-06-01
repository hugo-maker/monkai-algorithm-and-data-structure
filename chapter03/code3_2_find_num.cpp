#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N, v;
  cin >> N >> v;
  vector<int> array(N);

  for (int i = 0; i < N; ++i)
  {
    cin >> array[i];
  }

  int found_id = -1;
  for (int i = 0; i < N; ++i)
  {
    if (array[i] == v)
    {
      found_id = i;
      break;
    }
  }

  if (found_id != -1)
  {
    cout << v << " is at: " << found_id << endl;
  }
  else
  {
    cout << "Not found" << endl;
  }

  return 0;
}
