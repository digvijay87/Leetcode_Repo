/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 * #DynamicProgramming
 * #DailyChallange
 * #Knapsack
 * 
 Unbounded Knapsack:

Rod cutting problem
Coin Change 1
Coin Change 2
Maximum Ribbon Cut
Number Partitioning
0/1 Knapsack:

Subset Sum
Equal Sum Partition
Count of subset with given sum
Minimum subset sum difference
Target Sum
No of susbet with given difference
Count of subsets with given difference
Last Stone Weight 2(LC 1049)
 */


// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
      int zeros, ones;

      for (auto &s : strs) {
        zeros = ones = 0;
        
          for (int i = 0; i< s.size(); i++) {
            if (s[i] == '0')
                zeros++;
            else if (s[i] == '1')
                ones++;
        }

        for (int i = m; i >= zeros; i--) {
        for (int j = n; j >= ones; j--) {
              dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
        }
  }
  return dp[m][n];
}
};
// @lc code=end

