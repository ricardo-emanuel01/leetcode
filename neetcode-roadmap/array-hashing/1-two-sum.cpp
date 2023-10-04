# include <vector>
# include <unordered_map>


using namespace std;

// Brute force
vector<int> twoSum(vector<int>& nums, int target) {
    // At each element search for an element which complements the current to reach target
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) return {i, j};
        }
    }

    return {-1, -1};
}


// one do not have to traverse all the elements to look for an specific element
// one could store that in a map with its index, and check if the current complement exists
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> nums_map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (nums_map.count(complement)) return {i, nums_map[complement]};
        nums_map[nums[i]] = i;
    }

    return {-1, -1};
}
