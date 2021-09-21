#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;

void search(const Graph & G, int s)
{
  int N = (int)G.size();

  // stack<int> todo の場合、深さ優先探索になる
  queue<int> todo;

  seen[s] = true;
  todo.push(s);

  while(!todo.empty())
  {
    int v = todo.front();
    todo.pop();

    for (int x : G[v])
    {
      if (seen[x])
      {
        continue;
      }

      seen[x] = true;
      todo.push(x);
    }
  }
}

int main()
{
  int N, M;
  cin >> N >> M;

  Graph G(N);
  for (int i = 0; i < M; ++i)
  {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  seen.assign(N, false);
  search(G, 0);
  for (int i = 0; i < N; ++i)
  {
    if (!seen[i])
    {
      cout << "Error" << endl;
    }
  }
  return 0;
}
