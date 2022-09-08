class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> sub;
        vector<int> ans;
        for (int ind = 0; ind < nums.size(); ind++)
        {
            int i_sub = target - nums[ind];
            if(sub.find(i_sub) == sub.end())
            {
                sub[nums[ind]] = ind;
            }
            else
            {
                ans.push_back(sub[i_sub]);
                ans.push_back(ind);
            }
        }
        return ans;
    }
};