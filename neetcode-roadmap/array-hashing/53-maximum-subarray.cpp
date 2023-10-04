# include <vector>


using namespace std;

// One could calculate the sum of each subarray in O(n^3) which would be the brute force approach
int maxSubArray(vector<int>& nums) {
    int res = nums[0];
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int temp = 0;
            for (int k = i; k <= j; k++) {
                temp += nums[k];
            }
            res = max(res, temp);
        }
    }

    return res;
}

// One do not need to compute the entire sum every time
int maxSubArray(vector<int>& nums) {
    int res = nums[0];
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        int temp = 0;
        for (int j = i; j < size; j++) {
            temp += nums[j];
            res = max(res, temp);
        }
    }

    return res;
}

// We do not need to check every subarray, each subarray which has a negative sum could be discarded
int maxSubArray(vector<int>& nums) {
    int res = nums[0];
    int temp = res;

    for (int i = 1; i < nums.size(); i++) {
        if (temp < 0) temp = nums[i];
        else temp += nums[i];

        res = max(res, temp);
    }

    return res;
}
