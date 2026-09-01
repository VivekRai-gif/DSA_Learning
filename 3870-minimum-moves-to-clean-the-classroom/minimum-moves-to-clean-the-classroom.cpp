class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startR = 0, startC = 0;
        int litterCount = 0;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (classroom[r][c] == 'L') {
                    litterId[r][c] = litterCount++;
                }
            }
        }

        int targetMask = (1 << litterCount) - 1;

        // visited[row][col][remaining energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        queue<array<int, 4>> q;

        // row, col, remaining energy, collected mask
        q.push({startR, startC, energy, 0});
        visited[startR][startC][energy][0] = true;

        int moves = 0;
        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while (!q.empty()) {
            int levelSize = q.size();

            while (levelSize--) {
                auto [r, c, currentEnergy, mask] = q.front();
                q.pop();

                if (mask == targetMask) {
                    return moves;
                }

                // At zero energy, movement is impossible.
                if (currentEnergy == 0) {
                    continue;
                }

                for (auto& direction : directions) {
                    int nr = r + direction[0];
                    int nc = c + direction[1];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                        continue;
                    }

                    if (classroom[nr][nc] == 'X') {
                        continue;
                    }

                    int nextEnergy = currentEnergy - 1;

                    // Reaching a reset cell restores full energy.
                    if (classroom[nr][nc] == 'R') {
                        nextEnergy = energy;
                    }

                    int nextMask = mask;

                    if (classroom[nr][nc] == 'L') {
                        int id = litterId[nr][nc];
                        nextMask |= (1 << id);
                    }

                    if (!visited[nr][nc][nextEnergy][nextMask]) {
                        visited[nr][nc][nextEnergy][nextMask] = true;
                        q.push({nr, nc, nextEnergy, nextMask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};