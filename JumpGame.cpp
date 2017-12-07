#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

#define MAX 100
int map[MAX][MAX];
bool cache[MAX][MAX];
int T, N;

bool find(int x, int y) {
	if (x >= N || y>= N )
		return false;

	if (map[y][x] == 0)
		return true;

	if (cache[y][x] == false) 
		return false;

	if (find(x+map[y][x], y) || find(x, y+map[y][x]))
		return true;

	cache[y][x] = false;
	return false;
}

int main(int argc, char* argv[])
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				scanf("%d", &map[y][x]);
		//memset(cache, 0, sizeof(int)*N*N);
		//memset(cache, true, sizeof(bool)*N*N);

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cache[y][x]=true;
		/*
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++)
				printf("%3d", map[y][x]);
			printf("\n");
		}
		*/

		if (find(0, 0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

