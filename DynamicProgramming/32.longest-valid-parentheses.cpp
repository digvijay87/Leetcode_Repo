/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 * #Dynamic Programming
 * #Daily Challange
 */

// @lc code=start
/*
class Solution {
public:

    int longestValidParentheses(string s) {
        int n = s.size();

        vector<int> dp(n, 0);
        int maxL = 0;

        for(int i = 1; i < n; i++)
        {
            if(s[i] == ')' )
            {
                if(s[i-1] == '(')
                {
                    dp[i] = (i-2) >= 0 ? dp[i-2] + 2 : 2;
                    maxL = max(dp[i], maxL);
                }else{
                    if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '('){
                            dp[i] = dp[i-1] + 2 + ((i-dp[i-1]-2 >= 0)?dp[i-dp[i-1]-2]:0);
                            maxL = max(dp[i],maxL);
                        }
                }
            }
        }
        return maxL;
    }
    
   
};

*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxL=0;

        for(int i=0;i<s.size();i++)
        {
            int k = st.top();
            if(k!=-1 and s[i]==')' and s[k]=='(')
            {
                st.pop();
                maxL=max(maxL, i-st.top());
            }
            else
                st.push(i);
        }
        return maxL;
    }
};
// @lc code=end


