class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int negativeNums [10001] = {0};
        int positiveNums [10001] = {0};

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < 0)
                negativeNums[-nums[i]]++;
            else
                positiveNums[nums[i]]++;
        }

        int sumToReturn = 0;
        bool shouldAdd = true;

        for (int i = 10000; i>= 1; i--) {

            while (negativeNums[i] > 0) {

                if (shouldAdd) { 
                    sumToReturn += -i;
                    shouldAdd = false;
                }
                else 
                    shouldAdd = true;
                
                negativeNums[i] --;
            }

        }

        for (int i = 0; i< 10001; i++) {

            while (positiveNums[i] > 0) {

                if (shouldAdd) { 
                    sumToReturn += i;
                    shouldAdd = false;
                }
                else 
                    shouldAdd = true;
                
                positiveNums[i] --;
            }

        }

        return sumToReturn;
    }
};
