class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int total_count = 0;

        vector<unordered_map<int, int>> dp(n);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(nums[i]) - nums[j]; 

                if (diff > INT_MAX || diff < INT_MIN)
                    continue; 

                int difference = static_cast<int>(diff);

                dp[i][difference] += 1; 

                if (dp[j].count(difference)) {
                    dp[i][difference] += dp[j][difference];
                    total_count += dp[j][difference];
                }
            }
        }

        return total_count;
    }
};
