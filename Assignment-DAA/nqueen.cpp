// N-Queens Time Complexity

// Worst Case Time Complexity: O(N!)
// Explanation:
// For first column → N choices
// For second column → at most (N-1)
// For third → (N-2) ...
// Total ≈ N!

// Space Complexity: O(N)
// (for recursion stack + board storage)

class Solution {
    public:
        vector<vector<string>> ans;
        vector<string> board;
        int n;
    
        bool isSafe(int row, int col) {
            for (int i = 0; i < row; i++)
                if (board[i][col] == 'Q')
                    return false;
    
            for (int i = 1; i <= row; i++)
                if (col - i >= 0 && board[row - i][col - i] == 'Q')
                    return false;
    
            for (int i = 1; i <= row; i++)
                if (col + i < n && board[row - i][col + i] == 'Q')
                    return false;
    
            return true;
        }
    
        void solve(int row) {
            if (row == n) {
                ans.push_back(board);
                return;
            }
    
            for (int col = 0; col < n; col++) {
                if (isSafe(row, col)) {
                    board[row][col] = 'Q';
                    solve(row + 1);
                    board[row][col] = '.';
                }
            }
        }
    
        vector<vector<string>> solveNQueens(int N) {
            n = N;
            board = vector<string>(n, string(n, '.'));
            solve(0);
            return ans;
        }
    };
    