class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        if (n < 3) {
            return 0;
        }

        int left = 0;
        int right = n - 1;

        int leftMax = height[left];
        int rightMax = height[right];

        long long water = 0;

        while (left < right) {

            if (leftMax <= rightMax) {

                left++;

                leftMax = max(leftMax, height[left]);

                water += leftMax - height[left];

            } else {

                right--;

                rightMax = max(rightMax, height[right]);

                water += rightMax - height[right];
            }
        }

        return (int)water;
    }
};