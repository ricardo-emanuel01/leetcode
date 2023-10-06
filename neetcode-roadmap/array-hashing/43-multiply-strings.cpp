# include <string>
# include <vector>


using namespace std;

string multiply(string num1, string num2) {
    int n = num1.length();
    int m = num2.length();
    vector<int> result_number(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');
            int current = product + result_number[i + j + 1];

            result_number[i + j + 1] = current % 10;
            result_number[i + j] += current / 10;
        }
    }

    string res;
    for (int digit : result_number) {
        if (!res.empty() || digit != 0) res += digit + '0';
    }

    return res.empty() ? "0" : res;
}
