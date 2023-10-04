# include <string>


using namespace std;

int gcd(int a, int b) {
    int R;

    while ((a % b) > 0) {
        R = a % b;
        a = b;
        b = R;
    }

    return b;
}

string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) return "";

    int greatestCommonDivisor = gcd(str1.size(), str2.size());
    string res = str1.substr(0, greatestCommonDivisor);

    return res;
}