class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> arr;
        int i_front = 0, i_back = 0;
        int sum = nums[0];
        int sum_max = sum;

        for(int ind = 1; ind < nums.size(); ++ind)
        {
            // sum_max: maximum subarray sum
            // sum_temp: current subarray sum
            // sum: subarray sum - current value
            int sum_temp = nums[ind] + sum;

            if(sum < 0)
            {
                i_front = ind;
                i_back = ind;
                sum = nums[ind];
                sum_max = max(sum, sum_max);
            }
            else
            {
                if(sum_max <= sum_temp)
                {
                    i_back = ind;
                    sum_max = sum_temp;
                }
                sum = sum_temp;
            }
        }
        return sum_max;
    }
};