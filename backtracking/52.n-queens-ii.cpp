/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 * [51] N-Queens
 * #BackTrack 
 * #DailyChallange
 * 
 */

// @lc code=start

class Solution {
    vector<int> row;
    vector<int> diag;
    vector<int> antidiag;
    int n;
    int counter;
    
    bool can_be_placed(int r, int c)
    {
        int res = row[c] + diag[r-c + (2*n)] + antidiag[r+c];
        return (res == 0) ? true : false;
    }
    void helper(int r)
    {
        //Take all the next position in consideration 
        for(int c = 0; c < n; c++)
        {
            if(can_be_placed(r, c))
            {
                row[c] = 1;
                diag[r - c + (2 *n)] = 1;
                antidiag[r+c] = 1;
                
                if(r+1 == n) counter++;
                else
                    helper(r+1); // Once we are done with one board arrangement 
                
                //Clean up or backtrack
                row[c] = 0;
                diag[r - c + (2 *n)] = 0;
                antidiag[r+c] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        row.resize(n);
        diag.resize((4*n -1));
        antidiag.resize((2*n -1));
        this->n = n;
        counter = 0;
        
        helper(0);
        return counter;
    }
};
// @lc code=end

