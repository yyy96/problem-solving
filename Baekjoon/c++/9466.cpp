﻿#include <iostream>
#include <cstring>
#include <algorithm>
#define N 100001
using namespace std;

int T, n;
int student[N];
int path[N];
bool dto[N] = { false, };
bool team[N] = { false, };
int total;

void dfs(int lev, int start, int now) {
	if (student[now] == now) {
		if (lev == 0) {
			team[now] = true;
			total -= 1;
		}
		return;
	}
	if (lev != 0 && now == start) {
		total -= lev;
		for (int i = 0; i < lev; i++)
			team[path[i]] = true;
		return;
	}
	if (dto[now] || team[now]) return;

	path[lev] = now;
	dto[now] = true;
	dfs(lev + 1, start, student[now]);
	dto[now] = false;
	path[lev] = 0;
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> n;
		total = n;
		for (int i = 1; i <= n; i++)
			cin >> student[i];

		for (int i = 1; i <= n; i++) {
			if (team[i]) continue;
			dfs(0, i, i);
		}
		cout << total << "\n";
		memset(team, false, n + 1);
	}
	return 0;
}
