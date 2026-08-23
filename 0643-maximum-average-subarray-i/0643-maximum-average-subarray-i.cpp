class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxAverage = INT_MIN;
        int left = 0, subarraySum = 0;
        for(int right=0;right<n;right++)
        {
            subarraySum += nums[right];
            if(right - left + 1 == k)
            {
                double currAverage = (double)subarraySum / k;
                maxAverage = max(maxAverage, currAverage);
                subarraySum -= nums[left];
                left++;
            }
        }
        return maxAverage;
    }
};