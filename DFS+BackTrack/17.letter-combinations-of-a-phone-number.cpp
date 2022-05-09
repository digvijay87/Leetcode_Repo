/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
    vector<string> db = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    void helper(string digits, vector<string> &output, string curout, int idx, int len)
    {
        if(idx == len)
        {
            output.push_back(curout);
            return;
        }
        int digit = digits[idx] - '0';  // 2
        int n = db[digit].length();    // 3

        for(int i = 0; i < n ; i++)
        {
            curout.append(string(1, db[digit][i]));
            helper(digits, output, curout, idx+1, len);
            curout.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        
        int len = digits.length();
        if(len)
        {
            helper(digits, output, "", 0, len);
        }
        return output;
    }
};
// @lc code=end

/*
DFS, No back track

abc def ghi jkl mno pqrs tvu wxyz


234
class Solution {
private:
    vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    int len;
    
    void combo(int d, string& digits, string cur) {
        if (d == len) {
            ans.push_back(cur);
            return;
        }
        
        int x = digits[d] - '0', n = letters[x].size();
        
        for(int i=0; i<n; ++i){
            cur.append(string(1, letters[x][i]));
            combo(d+1, digits, cur);
            cur.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        len = digits.size();
        if (len)
            combo(0, digits, "");
        return ans;
    }
};




*/