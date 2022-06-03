/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *  #DFS #Backtrace #DailyChallange #Google
 *  Classic backtrace template. 
 */

// @lc code=start
class Solution {
    vector<vector<int>> output;
    int K;
    int N;
    
    void helper(vector<int> &temp, int idx, int &sum)
    {
        if(temp.size() == K and sum == N)
        {
            /*
            Note : 2 :: is the size is k and sum is N add to the output.
            */
            output.push_back(temp);
            return;
        }
        /*Note 3.1:: 
            since we are adding all the candidates, we need to check if currently
            added candidate is valid or not. 
            if either the current candidate is exceeding the num or the size of the 
            temp is exceeding we return back and pop up the currently added element 
            also subtract from the running sum ( see note 3.2)
        */
        if(sum > N || temp.size() > K) return;
        
        for(int i = idx; i < 10; i++)
        {
            /*
            1. This is the place we need to think should we push cur value or 
            not ? I thought about it cam eup with an idea to push all the value
            and add it to the sum. it the temp vector is valid add it to the output(note - 2).
            is not discard the currently added value.
            */
            temp.push_back(i);  
            sum += i;
            
            helper(temp, i+1, sum);
            /* Note 3.2 :: remove the current candidate from the sum and 
            temp vector */
            sum -= temp.back();
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->K = k;
        this->N = n;
        vector<int> temp;
        int sum  = 0;
        helper(temp, 1, sum);
        return output;
    }

};
// @lc code=end



