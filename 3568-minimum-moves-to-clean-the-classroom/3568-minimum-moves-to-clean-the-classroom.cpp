class Solution {
public:
    struct Node {
        int r, c;
        int mask;
        int energy;
        int dist;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0)
            return 0;

        int target = (1 << cnt) - 1;

        // best[r][c][mask] = maximum energy reached
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << cnt, -1))
        );

        queue<Node> q;

        q.push({sr, sc, 0, energy, 0});
        best[sr][sc][0] = energy;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {

            Node cur = q.front();
            q.pop();

            if (cur.mask == target)
                return cur.dist;

            if (cur.energy == 0)
                continue;

            for (int d = 0; d < 4; d++) {

                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                int newEnergy = cur.energy - 1;
                int newMask = cur.mask;

                if (classroom[nr][nc] == 'L') {
                    newMask |= (1 << id[nr][nc]);
                }

                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                // Already reached this state with more energy
                if (best[nr][nc][newMask] >= newEnergy)
                    continue;

                best[nr][nc][newMask] = newEnergy;

                q.push({
                    nr,
                    nc,
                    newMask,
                    newEnergy,
                    cur.dist + 1
                });
            }
        }

        return -1;
    }
};