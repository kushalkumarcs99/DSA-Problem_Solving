class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        int maxTillHere = 0;

        for(int i = 0;i<n;i++)
        {
            if(nums[i]==0)
            {
                ans = max(ans, maxTillHere);
                maxTillHere = 0;
            }
            else
            {
                maxTillHere++;
            }
        }
        ans = max(ans, maxTillHere);
        return ans;
    }
};