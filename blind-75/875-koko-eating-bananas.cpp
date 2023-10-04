# include <algorithm>
# include <cmath>
# include <vector>


using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int res = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long hours = 0;

        for (int x : piles) {
            hours += ceil((double)x / mid);
        }

        if (hours <= h) {
            res = min(res, mid);
            right = mid - 1;
        } else left = mid + 1;
    }

    return res;
}
