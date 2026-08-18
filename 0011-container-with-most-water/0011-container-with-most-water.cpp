class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int result = 0;
        int left = 0, right = n-1;
        while(left<=right)
        {
            int currentWidth = right - left;
            int currentLength = min(height[left], height[right]);

            int currentMaxWater = currentWidth * currentLength;

            result = max(currentMaxWater, result);

            if(height[left] <= height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return result;
    }
};