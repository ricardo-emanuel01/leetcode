# include <vector>
# include <unordered_set>


using namespace std;


// First approach in which i did not manage to find a function to the index of the square
bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<int>> groups(27);

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] != '.') {
                int current = board[i][j] - '0';
                // Check each row
                if (groups[i].find(current) != groups[i].end()) {
                    return false;
                } else {
                    groups[i].insert(current);
                }

                // Check each column
                if (groups[j + 9].find(current) != groups[j + 9].end()) {
                    return false;
                } else {
                    groups[j + 9].insert(current);
                }

                // Check each subsquare
                if (i < 3) {
                    if (j < 3) {
                        if (groups[18].find(current) != groups[18].end()) {
                            return false;
                        } else {
                            groups[18].insert(current);
                        }
                    } else if (j < 6) {
                        if (groups[19].find(current) != groups[19].end()) {
                            return false;
                        } else {
                            groups[19].insert(current);
                        }
                    } else {
                        if (groups[20].find(current) != groups[20].end()) {
                            return false;
                        } else {
                            groups[20].insert(current);
                        }
                    }
                } else if (i < 6) {
                    if (j < 3) {
                        if (groups[21].find(current) != groups[21].end()) {
                            return false;
                        } else {
                            groups[21].insert(current);
                        }
                    } else if (j < 6) {
                        if (groups[22].find(current) != groups[22].end()) {
                            return false;
                        } else {
                            groups[22].insert(current);
                        }
                    } else {
                        if (groups[23].find(current) != groups[23].end()) {
                            return false;
                        } else {
                            groups[23].insert(current);
                        }
                    }
                } else {
                    if (j < 3) {
                        if (groups[24].find(current) != groups[24].end()) {
                            return false;
                        } else {
                            groups[24].insert(current);
                        }
                    } else if (j < 6) {
                        if (groups[25].find(current) != groups[25].end()) {
                            return false;
                        } else {
                            groups[25].insert(current);
                        }
                    } else {
                        if (groups[26].find(current) != groups[26].end()) {
                            return false;
                        } else {
                            groups[26].insert(current);
                        }
                    }
                }
            }
        }
    }

    return true;
}


bool isValidSudoku(vector<vector<char>>& board) {
    const int n = 9;
    bool rows[n][n] = {false};
    bool columns[n][n] = {false};
    bool squares[n][n] = {false};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '.') {
                // As it goes from 1-9 we need to index it from 0-8
                int index = board[i][j] - '0' - 1;
                int area = (i / 3) * 3 + j / 3;

                if (rows[index][i] || columns[index][j] || squares[index][area]) {
                    return false;
                }

                rows[index][i] = true;
                columns[index][j] = true;
                squares[index][area] = true;
            }
        }
    }

    return true;
}
