class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int left = 0, right = n - 1;
        int maxAmount = 0;
        while(left < right)
        {
            int minHeight = min(height[left], height[right]);
            int width = right - left;
            int currAmount = minHeight * width;
            maxAmount = max(maxAmount, currAmount);
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxAmount;
    }
};