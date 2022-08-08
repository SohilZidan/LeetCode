class UnionFind {
    
    

    public:
    vector<int> parent, rank;
    int n;
    
    UnionFind(int n){
        rank.resize(n, 0);
        parent.resize(n);
        this->n = n;
        makeSet();
    }
    void makeSet(){
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find_element(int x){
        if(parent[x] != x)
            parent[x] = find_element(parent[x]);
        return parent[x];
    }
    
    void union_sets(int x, int y){
        int xRoot = find_element(x);
        int yRoot = find_element(y);
        cout << to_string(x) + ", " + to_string(xRoot) << endl;
        cout << to_string(y) + ", " + to_string(yRoot) << endl;
        if(xRoot == yRoot) return;

        if(rank[xRoot] > rank[yRoot])
        {
            cout << to_string(parent[xRoot]) + ", " + to_string(parent[yRoot]) << endl;
            parent[yRoot] = xRoot;
        }
        else if (rank[xRoot] < rank[yRoot])
        {
            cout << to_string(parent[xRoot]) + ", " + to_string(parent[yRoot]) << endl;
            parent[xRoot] = yRoot;
        }
        else
        {
            cout << to_string(parent[xRoot]) + ", " + to_string(parent[yRoot]) << endl;
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    
    }
    
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        UnionFind *uf = new UnionFind(rows*cols);
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '0') continue;
                
                // cout << to_string(i) + ", " + to_string(j) + ", " + to_string() << endl;
                if(i-1 >= 0 && grid[i-1][j] == '1')
                    uf->union_sets(i*cols+j, (i-1)*cols+j);
                if(j+1 < cols && grid[i][j+1] == '1')
                    uf->union_sets(i*cols+j, i*cols+(j+1));
                if(i+1 < rows && grid[i+1][j] == '1')
                    uf->union_sets(i*cols+j, (i+1)*cols+j);
                if(j-1 >= 0 && grid[i][j-1] == '1')
                    uf->union_sets(i*cols+j, i*cols+(j-1));
            }
        }
        
        // frequency array
        vector<int> *freq = new vector<int>(cols*rows, 0);
        int islandsCount = 0;
        
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                // cout<< to_string(uf.rank[row*cols+col]) << ", ";
                if(grid[row][col] == '0') continue;
                
                int xRoot = uf->find_element(row*cols+col);
                
                if((*freq)[xRoot] == 0)
                    islandsCount ++;
                (*freq)[xRoot] ++;
            }
            // cout<<endl;
        }
        
        return islandsCount;
    }
};