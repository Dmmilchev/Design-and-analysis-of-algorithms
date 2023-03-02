class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int negativeNums [50001] = {0};
        int positiveNums [50001] = {0};

        int arrSize = nums.size();
        for (int i=0; i < arrSize; ++i) {

            if (nums[i] < 0)
                negativeNums[-nums[i]]++;
            else
                positiveNums[nums[i]]++;

        }

        vector<int> result;
        for (int i = 50000; i>=0; i--) {
            while (negativeNums[i] > 0) {
                result.push_back(-i);
                negativeNums[i]--;
            }
        }

        for (int i=0; i < 50001; i++) {
            while (positiveNums[i] > 0) {
                result.push_back(i);
                positiveNums[i]--;
            }
        }

        return result;
    }
};