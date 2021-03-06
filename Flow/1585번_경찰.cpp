﻿/*
BOJ 1585 - 경찰
https://www.acmicpc.net/problem/1585
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
const int S = 101, E = 102;
struct mcmf {
	struct edge {
		int v, c, op, cost;
	};
	int dist[E + 1], p[E + 1], pidx[E + 1];
	bool inq[E + 1];
	vector<edge> eg[E + 1];
	void init() {
		for (int i = 0; i <= E; i++) eg[i].clear();
	}
	void addEdge(int a, int b, int f, int cost) {
		eg[a].push_back({ b,f,(int)eg[b].size(),cost });
		eg[b].push_back({ a,0,(int)eg[a].size() - 1,-cost });
	}
	bool SPFA() {
		memset(inq, false, sizeof(inq));
		memset(p, -1, sizeof(p));
		fill(dist, dist + E + 1, INF);
		queue<int> q;
		inq[S] = true;
		dist[S] = 0;
		q.push(S);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			inq[cur] = false;
			int sz = eg[cur].size();
			for (int k = 0; k < sz; k++) {
				edge i = eg[cur][k];
				if (i.c > 0 && dist[cur] + i.cost < dist[i.v]) {
					dist[i.v] = dist[cur] + i.cost;
					p[i.v] = cur;
					pidx[i.v] = k;
					if (!inq[i.v]) {
						inq[i.v] = true;
						q.push(i.v);
					}
				}
			}
		}
		return p[E] != -1;
	}
	pii getAns() {
		pii ret = { 0,0 };
		while (SPFA()) {
			int mn = INF;
			for (int i = E; i != S; i = p[i]) {
				mn = min(mn, eg[p[i]][pidx[i]].c);
			}
			ret.first += mn;
			for (int i = E; i != S; i = p[i]) {
				ret.second += mn * eg[p[i]][pidx[i]].cost;
				eg[p[i]][pidx[i]].c -= mn;
				eg[i][eg[p[i]][pidx[i]].op].c += mn;
			}
		}
		return ret;
	}
} mf;
int srt[50], ed[50];
int main() {
	int n, t, f;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &srt[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &ed[i]);
	}
	scanf("%d %d", &t, &f);

	for (int i = 0; i < n; i++) {
		mf.addEdge(S, i, 1, 0);
		mf.addEdge(i + n, E, 1, 0);
		for (int j = 0; j < n; j++) {
			if (srt[i] < ed[j]) {
				int x = ed[j] - srt[i];
				mf.addEdge(i, j + n, 1, t > x ? min(f, (t - x)*(t - x)) : 0);
			}
		}
	}
	pii ans = mf.getAns();
	if (ans.first != n) return !printf("-1");
	mf.init();
	for (int i = 0; i < n; i++) {
		mf.addEdge(S, i, 1, 0);
		mf.addEdge(i + n, E, 1, 0);
		for (int j = 0; j < n; j++) {
			if (srt[i] < ed[j]) {
				int x = ed[j] - srt[i];
				mf.addEdge(i, j + n, 1, t > x ? max(-f, -(t - x)*(t - x)) : 0);
			}
		}
	}
	ans.first = -mf.getAns().second;
	printf("%d %d", ans.second, ans.first);

	return 0;
}