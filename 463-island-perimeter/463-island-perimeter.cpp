class Solution {
public:
    vector<vector<int>> possible_moves{
        {-1, 0},
        {0, +1},
        {+1, 0},
        {0, -1}
    };

    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;

        for(size_t row = 0; row < grid.size(); row++)
        {
            for(size_t col = 0; col < grid[0].size(); col++)
            {
                // cout<<to_string(row) + ", " + to_string(col) << endl;
                // cout<<numberOfNeighbors(row, col, grid)<<endl;
                if(grid[row][col] == 1) 
                {
                    perimeter += 4 - numberOfNeighbors(row, col, grid);
                    // cout << perimeter << endl;
                }
            }
        }
        return perimeter;
    }
    
    int numberOfNeighbors(const int& row, const int& col, const vector<vector<int>>& grid)
    {
        int moves = 0;
        for(const auto& p_move: possible_moves)
        {
            int r = row + p_move[0], c = col + p_move[1];
            // cout << to_string(r) + ", " + to_string(c) << endl;
            // cout << (isValidIndex(r, c, grid.size(), grid[0].size()) && (grid[r][c] == 1)) << endl;
            if(isValidIndex(r, c, grid.size(), grid[0].size()) && (grid[r][c] == 1)) moves++;
        }
        return moves;
    }
    
    bool isValidIndex(int row, int col, int rows, int cols)
    {
        // cout << (row >= 0 & row < rows & col >= 0 & col < cols) << endl;
        return row >= 0 & row < rows & col >= 0 & col < cols;
    }
    
//     int islandPerimeter(vector<vector<int>>& grid) {
//         int col = 0, row = 1;
//         vector<vector<int>> possible_moves{
//             {-1, 0},
//             {0, +1},
//             {+1, 0},
//             {0, -1}
//         };
        
//         // find the first element
//         bool found = false;
//         while(!found & row < grid.size())
//         {
//             col = 0;
//             while(!found & col < grid[0].size())
//             {
//                 found = (grid[row][col] == 1);
//                 col++;
//             }
//             row++;
//         }

        
//         unordered_map<pair<int,int>, unordered_set<pair<int, int>>> graph;
//         queue<pair<int, int>> q;
//         unordered_set<pair<int, int>> visited;
//         q.push(make_pair<row, col>);
//         while(!q.empty())
//         {
//             auto node = q.front();
//             q.pop();
            
//             if(visited.find(node) != visited.end()) continue;
//             visited.insert(q);
            
//             for(const auto& p_move: possible_moves)
//             {
                
//             }
//         }
//     }
};