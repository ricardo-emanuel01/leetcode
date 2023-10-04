# include <unordered_set>
# include <vector>


using namespace std;

vector<int> onlyInFirst(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> onlyInFirst;
    unordered_set<int> existsInSecond;

    for (int x : nums2) {
        existsInSecond.insert(x);
    }

    for (int x : nums1) {
        if (!existsInSecond.count(x)) {
            onlyInFirst.insert(x);
        }
    }

    return vector<int> (onlyInFirst.begin(), onlyInFirst.end());
}

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<int> onlyInNums1 = onlyInFirst(nums1, nums2);
    vector<int> onlyInNums2 = onlyInFirst(nums2, nums1);

    return {onlyInNums1, onlyInNums2};
}
