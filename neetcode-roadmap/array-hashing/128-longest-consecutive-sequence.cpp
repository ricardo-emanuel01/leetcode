# include <vector>
# include <unordered_set>


using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    unordered_set<int> nums_set(nums.begin(), nums.end());
    int res = 0;

    for (int x : nums) {
        if (nums_set.find(x - 1) == nums_set.end()) {
            int currentSeq = 0;
            while (nums_set.find(x + currentSeq) != nums_set.end()) {
                currentSeq++;
            }

            res = max(res, currentSeq);
        }
    }

    return res;
}
