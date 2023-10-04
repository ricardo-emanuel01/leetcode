# include <string>
# include <unordered_set>


using namespace std;

string reverseVowels(string s) {
    unordered_set<char> u_set = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (u_set.count(s[left]) && u_set.count(s[right])) {
            swap(s[left], s[right]);
        }

        while (!u_set.count(s[left]) && (left < right)) left++;
        while (!u_set.count(s[right]) && (right > left)) right++;
    }

    return s;
}
