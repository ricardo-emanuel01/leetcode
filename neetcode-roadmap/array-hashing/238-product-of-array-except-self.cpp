# include <vector>


using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int prefix, postfix;

    vector<int> res(n);

    prefix = 1;
    for (int i = 0; i < n; i++) {
        res[i] = prefix;
        prefix *= nums[i];
    }

    postfix = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] *= postfix;
        postfix *= nums[i];
    }

    return res;
}
