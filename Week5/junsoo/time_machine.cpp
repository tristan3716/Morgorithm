#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> pii;//시작, 도착 저장위함

const int INF = 987654321;

vector<pii> adj[502];
int dist[502];
bool visit[502];

int main()
{
	int V, E;
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++)
	{
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);

		adj[from].push_back({ to, val });
	}

	fill(dist, dist + 502, INF);//초기화
	dist[1] = 0;

	int n = 0;
	while (n <= V)
	{
		for (int i = 1; i <= V; i++)
		{
			int here = i;
			int cost = dist[here];
			int len = adj[i].size();
			for (int j = 0; j < len; j++)
			{
				int next = adj[here][j].first;
				int nextCost = adj[here][j].second + dist[here];

				if (dist[next] > nextCost)
				{
					if (n == V)
					{
						printf("-1\n");
						return 0;
					}
					dist[next] = nextCost;
				}
			}
		}
		n++;
	}

	for (int i = 2; i <= V; i++)
	{
		if (dist[i] == INF)
			printf("-1\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}
