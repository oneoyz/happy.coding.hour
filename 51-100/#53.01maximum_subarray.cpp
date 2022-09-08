class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> arrSelf;
        vector<int> arrFront;
        vector<int> minFront;
        arrSelf.push_back(nums[0]);
        arrFront.push_back(0);
        
        int min_front = 0;
        minFront.push_back(min_front);
        for(int idx=1; idx<nums.size(); idx++)
        {
            // the sum of window [0,i]: (sum to i) - [previous sum to (i-win_size)]
            // so the largest (sum to i) - the smallest [previous sum to (i-win_size)]
            arrFront.push_back(arrSelf[idx-1]);
            arrSelf.push_back(arrSelf[idx-1]+nums[idx]);
            
            // caculate the smallest value of previous list
            min_front = min_front<arrFront[idx]?min_front:arrFront[idx];
            minFront.push_back(min_front);
        }
        
        int result = nums[0];
        for(int idx=1; idx<arrSelf.size(); idx++)
        {
            int max_sum = arrSelf[idx] - minFront[idx];
            result = result>max_sum?result:max_sum;
        }
        return result;
    }
};