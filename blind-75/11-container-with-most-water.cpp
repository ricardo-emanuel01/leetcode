# include <vector>


using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size();

    int res = 0;

    while (left < right) {
        int currentArea = min(height[left], height[right]) * (right - left);
        res = max(res, currentArea);

        if (height[left] < height[right]) left++;
        else right--;
    }

    return res;
}
