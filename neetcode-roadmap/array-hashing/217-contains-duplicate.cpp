# include <vector>
# include <unordered_set>


using namespace std;

// At each element we could search in the rest of the array for another element with same value
bool containsDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] == nums[j]) return true;
        }
    }

    return false;
}

// Like two sum we could actually store each value in an unordered_set which will have time complexity
// of lookup O(1)
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> nums_set;

    for (int i = 0; i < nums.size(); i++) {
        if (nums_set.find(nums[i]) != nums_set.end()) {
            return true;
        }

        nums_set.insert(nums[i]);
    }

    return false;
} 
