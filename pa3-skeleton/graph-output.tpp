    class Solution
    {
    public:
        int size;
        int shortestPathBinaryMatrix(vector<vector<int>> &grid)
        {
            size = grid.size();
            vector<vector<bool>> visit(size, vector<bool>(size, false));
            return helper(grid, 0, 0, visit);
        }
        int helper(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &visited)
        {
            if (x >= size || y >= size)
                return 0;
            if (x == size && y == size)
                return 1;
            visited[x][y] = true;
            if (int a = helper(grid, x + 1, y + 1, visited))
                return a + 1;
            if (int a = helper(grid, x - 1, y - 1, visited))
                return a + 1;
            if (int a = helper(grid, x - 1, y + 1, visited))
                return a + 1;
            if (int a = helper(grid, x + 1, y - 1, visited))
                return a + 1;
            if (int b = helper(grid, x + 1, y, visited))
                return b + 1;
            if (int b = helper(grid, x - 1, y, visited))
                return b + 1;
            if (int c = helper(grid, x, y + 1, visited))
                return c + 1;
            if (int c = helper(grid, x, y - 1, visited))
                return c + 1;
            return 0;
        }
    };