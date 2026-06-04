class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Pick each element one by one
        for(int i = 0; i < nums.size(); i++) {

            // Compare it with all remaining elements
            for(int j = i + 1; j < nums.size(); j++) {

                // Check if their sum equals target
                if(nums[i] + nums[j] == target) {

                    // Return the indices
                    return {i, j};
                }
            }
        }