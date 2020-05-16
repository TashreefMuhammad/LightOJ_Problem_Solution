#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int t, w, h, i, j, start_i, start_j, cnt, cnt_t = 0;
    queue <pair<int, int>> q;
    pair <int, int> tmp;

    cin >> t;

    while(++cnt_t <= t)
    {
        cin >> w >> h;

        char mat[h][w];

        for(i = 0; i < h; i++)
            for(j = 0; j < w; j++)
            {
                cin >> mat[i][j];
                if(mat[i][j] == '@')
                {
                    start_i = i;
                    start_j = j;
                }
            }

        cnt = 0;
        q.push(make_pair(start_i, start_j));

        while(!q.empty())
        {
            cnt++;
            tmp = q.front();
            i = tmp.first;
            j = tmp.second;
            q.pop();

            if(i > 0 && mat[i-1][j] == '.')
            {
                q.push(make_pair(i-1, j));
                mat[i-1][j] = '#';
            }
            if(j > 0 && mat[i][j-1] == '.')
            {
                q.push(make_pair(i, j-1));
                mat[i][j-1] = '#';
            }
            if(j < w-1 && mat[i][j+1] == '.')
            {
                q.push(make_pair(i, j+1));
                mat[i][j+1] = '#';
            }
            if(i < h-1 && mat[i+1][j] == '.')
            {
                q.push(make_pair(i+1, j));
                mat[i+1][j] = '#';
            }
        }
        cout << "Case " << cnt_t << ": " << cnt << "\n";
    }

    return 0;
}
/*
4
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
*/
