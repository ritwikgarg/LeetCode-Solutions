class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (int)sumLesserThanEqualToGoal(nums, goal) - (int)sumLesserThanEqualToGoal(nums, goal-1);
    }

    long long sumLesserThanEqualToGoal(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        
        int left = 0;
        int right = 0;
        int count = 0;
        long long sum = 0LL;

        int n = nums.size();

        while (right < n) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left];
                left++; 
            }

            count += right-left+1;
            right++;
        }

        return count;
    }
};