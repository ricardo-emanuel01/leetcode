# include <string>
# include <unordered_map>


using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    // With a lookup table we establish that the worst case in access will always be O(1)
    // Because it is only lowercase english letters
    int lookup[26] = {0};
    for (char x : s) {
        int currentIdx = x - 'a';
        lookup[currentIdx]++;
    }

    for (char x : t) {
        int currentIdx = x - 'a';
        lookup[currentIdx]--;
    }

    for (int x : lookup) {
        if (x != 0) return false;
    }

    return true;
}


// Follow up question: what if the inputs contain unicode character?
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, int> unicode_map;

    for (char x : s) {
        if (unicode_map.find(x) == unicode_map.end()) {
            unicode_map[x] = 1;
        } else {
            unicode_map[x]++;
        }
    }

    for (char x : t) {
        if (unicode_map.find(x) == unicode_map.end()) {
            return false;
        } else {
            unicode_map[x]--;
        }
    }

    for (pair<char, int> x : unicode_map) {
        if (x.second != 0) {
            return false;
        }
    }

    return true;
}
