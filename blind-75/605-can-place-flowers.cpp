# include <vector>


using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int flowersToPlace = 0;
    int size = flowerbed.size();

    for (int i = 0; i < size; i++) {
        if (flowerbed[i] == 0) {
            bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
            bool rightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);

            if (leftEmpty && rightEmpty) {
                flowerbed[i] = 1;
                flowersToPlace++;

                if (flowersToPlace >= n) return true;
            }
        }
    }

    return flowersToPlace == n;
}
