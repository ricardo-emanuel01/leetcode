# include <string>
# include <unordered_set>


using namespace std;

int maxVowels(string s, int k) {
    int res = 0;
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < k; i++) {
        res += vowels.count(s[i]);
    }

    int temp = res;
    for (int i = k; i < s.length(); i++) {
        temp += vowels.count(s[i]) - vowels.count(s[i - k]);
        res = max(res, temp);
    }

    return res;
}
