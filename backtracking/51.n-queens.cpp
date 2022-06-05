/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 * [52] N-Queens II
 * #Backtrack
 * #DailyChallange
 */

// @lc code=start
class Solution {
    vector<int> row;
    vector<int> diag;
    vector<int> antidiag;
    bool can_be_placed(int r, int c,int n)
    {
        int res = 0;
        res = row[c] + diag[ r - c + (n*2)] + antidiag[r+c];
        
            
        return (res == 0) ? true : false;    
    }
    void backtrack(int r, int n, vector<string> &board, vector<vector<string>> &ans)
    {
        for(int c = 0; c < n; c++)
        {
            if(can_be_placed(r,c,n))
            {
                row[c] = 1;
                diag[r-c + (n*2)] = 1;
                antidiag[r+c] = 1;
                board[r][c] = 'Q';
              //  printf("%d, %d\n",r,c);
                if(r+1 == n)
                {
                    ans.push_back(board);
                }else{
                    backtrack(r+1, n, board, ans);
                }
               // printf("cleanup %d, %d\n",r,c);
                board[r][c] = '.';
                row[c] = 0;
                diag[r-c + n*2] = 0;
                antidiag[r+c] = 0;                
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n <= 0) return {{}};
        
        vector<string> board(n,string(n,'.'));
        
        row.resize(n);
        diag.resize(4*n -1);
        antidiag.resize(2*n - 1);
        
        
        vector<vector<string>> ans;
        
        backtrack(0,n,board,ans);
        
        return ans;
    }
};
// @lc code=end

