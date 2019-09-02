#include <stdio.h>
#include <queue>


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

int x, y;
int total_zero;
int nfiled[1001][1001];

typedef struct pos{
	int nx, ny;
};

queue <pos> que[2];

int dirx[] = { 0, 0, 1, -1 };
int diry[] = { 1, -1, 0, 0 };

int bfs()
{
	int que_num = 0;
	int cur_zero = 0;
	pos cur = { 0, 0 };
	pos next = { 0, 0 };
	int time = 0;

	while (!que[que_num].empty())
	{
		while (!que[que_num].empty())
		{
			cur = que[que_num].front();
			que[que_num].pop();

			for (int i = 0; i < 4; i++)
			{
				next.nx = cur.nx + dirx[i];
				next.ny = cur.ny + diry[i];

				if (next.nx >= 0 && next.nx < x && next.ny >= 0 && next.ny < y && nfiled[next.ny][next.nx] == 0)
				{
					nfiled[next.ny][next.nx] = 1; 
					cur_zero++;
					que[!que_num].push(next);
				}
			}
		}
		que_num = !que_num;
		time++;
	}
	if (cur_zero != total_zero)
		time = 0;


	return time - 1;

}

int main()
{
	int t;
	int test_case;

	freopen("input.txt", "r", stdin);

	scanf("%d", &t);
	for (test_case = 1; test_case <= t; ++test_case)
	{
		scanf("%d %d", &x, &y);
		total_zero = 0;
		for (int i = 0; i < y; i++){
			for (int j = 0; j < x; j++){
				scanf("%d", &nfiled[i][j]);
				if (nfiled[i][j] == 0){
					total_zero++;
				}
				else if (nfiled[i][j] == 1){
					que[0].push({ j, i });
				}
			}
		}
		
		if (total_zero == 0){
			printf("%d\n", 0);
			return 0;
		}
		
		printf("%d\n", bfs());

	}
	return 0;
}