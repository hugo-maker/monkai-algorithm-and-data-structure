#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;

vector<int> BFS(const Graph & G, int s)
{
  int N = (int)G.size();

  vector<int> dist(N, -1);
  queue<int> que;

  dist[s] = 0;
  que.push(s);

  while(!que.empty())
  {
    int v = que.front();
    que.pop();

    for (int x : G[v])
    {
      if (dist[x] != -1)
      {
        continue;
      }

      dist[x] = dist[v] + 1;
      que.push(x);
    }
  }

  return dist;
}

int main()
{
  int N, M, s, t;
  cin >> N >> M >> s >> t;

  Graph G(N);
  for (int i = 0; i < M; ++i)
  {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  vector<int> dist = BFS(G, s);

  if (dist[t] != -1)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
