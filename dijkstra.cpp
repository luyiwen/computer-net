#include "pch.h"
#include"router.h"
#include <iostream>

using namespace std;

bool Router::Dijkstra(Graph& G, int ch)
{
	cout << "Â¬ÒÕö©" << endl;
	int v0 = G.getVPos(ch);
	if (v0 == -1)
		return false;
	int maxV = G.getnumV();
	int min, n;
	int *s;
	s = new int[maxV];
	for (int i = 0; i < maxV; i++)
	{
		dist[i] = G.getcost(v0, i);
		s[i] = 0;
		path[i] = -1;
	}

	s[v0] = 1;
	dist[v0] = 0;

	for (int i = 0; i < maxV - 1; i++)
	{
		min = 999;
		for (int j = 0; j < maxV; j++)
		{
			if (s[j] == 0 && min > dist[j])
			{
				min = dist[j];
				n = j;
			}
		}
		if (min == 999)
			continue;

		s[n] = 1;
		for (int k = 0; k < maxV; k++)
		{
			if (s[k] == 0 && G.getcost(n, k) != 999 && dist[k] > dist[n] + G.getcost(n, k))
			{
				dist[k] = dist[n] + G.getcost(n, k);
				path[k] = n;
			}
		}

	}
	return true;
}
