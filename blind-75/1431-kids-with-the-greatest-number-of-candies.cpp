# include <algorithm>
# include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int x) {
    int n = candies.size();
    vector<bool> res(n);

    int maxNumberCandy = *max_element(candies.begin(), candies.end());

    for (int i = 0; i < n; i++) {
        if (candies[i] + x >= maxNumberCandy) res[i] = true;
        else res[i] = false;
    }

    return res;
}
