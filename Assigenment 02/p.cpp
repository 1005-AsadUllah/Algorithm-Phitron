#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// Function to check if a cell is valid to move into
bool isValidCell(vector<vector<char>> &maze, int row, int col)
{
    int numRows = maze.size();
    int numCols = maze[0].size();

    return (row >= 0 && row < numRows && col >= 0 && col < numCols && maze[row][col] != '#');
}

// Function to find the path using BFS
void findPath(vector<vector<char>> &maze, pair<int, int> start)
{
    int numRows = maze.size();
    int numCols = maze[0].size();

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        for (auto dir : directions)
        {
            int newRow = current.first + dir.first;
            int newCol = current.second + dir.second;

            if (isValidCell(maze, newRow, newCol))
            {
                maze[newRow][newCol] = 'X'; // Mark the cell as part of the path
                q.push({newRow, newCol});
            }
        }
    }
}

int main()
{
    int numRows, numCols;
    cin >> numRows >> numCols;

    vector<vector<char>> maze(numRows, vector<char>(numCols));
    pair<int, int> start;

    // Input the maze
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'R')
            {
                start = {i, j}; // Save the starting position
            }
        }
    }

    findPath(maze, start); // Find the path

    // Output the maze with marked path
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }

    return 0;
}
