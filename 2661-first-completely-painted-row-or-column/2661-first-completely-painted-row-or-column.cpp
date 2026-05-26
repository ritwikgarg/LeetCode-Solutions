class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int n = rows*cols;
        
        vector<int> rowSets(rows, cols);
        vector<int> colSets(cols, rows);
        vector<pair<int,int>> elemSet(n);
        
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
            {
                    elemSet[grid[i][j]-1] = {i, j};
            }
        }

        for (int k=0; k<n; k++) {
            int ele = arr[k];
            pair<int, int> coord = elemSet[ele-1];
            int row = coord.first;
            int col = coord.second;
            
            rowSets[row]--;
            if (rowSets[row] == 0) return k;

            colSets[col]--;
            if (colSets[col] == 0) return k;
        }
        
        return -1;
    }
};
