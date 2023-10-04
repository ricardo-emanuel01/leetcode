# include <algorithm>
# include <vector>
# include <string>
# include <unordered_map>


using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> strings_map;
    vector<vector<string>> res;

    for (string x : strs) {
        string current = x;
        sort(current.begin(), current.end());
        strings_map[current].push_back(x);
    }

    for (pair<string, vector<string>> x : strings_map) {
        res.push_back(x.second);
    }

    return res;
}
