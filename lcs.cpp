#include <iostream>
#include <vector>
#include <string>

//LCS:  Finds the longest common subsequence of two strings using
//      DP. 
//Note: Strings start on 0 not 1, so index k-1
static std::string result;

void print_lcs(std::vector<std::string> b, std::string X, int i, int j) {
    int m = static_cast<int> (X.size());
    auto idx = [=](int x, int y) { return x*m + y; };
    if (i == 0 || j == 0) 
        return;
    if (b[idx(i,j)] == "diag") {               //Match
        print_lcs(b, X, i-1, j-1);
        result = result + X[i-1];
    }
    else if (b[idx(i,j)] == "up") {           
        print_lcs(b, X, i-1, j);
    }
    else { 
        print_lcs(b, X, i, j-1);
    }
}

int main() {
    std::string X{"ABCBDAB"};
    std::string Y{"BDCABA"};
    const int m = static_cast<int> (X.size());
    const int n = static_cast<int> (Y.size());
    const int size = (m+1)*(n+1);
    std::vector<std::string> b(size);
    std::vector<int> c(size);
    auto idx = [=](int x, int y) { return x*m + y; };

    for (auto &i:c) i =0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i-1] == Y[j-1]) {
                c[idx(i,j)] = c[idx(i-1,j-1)] + 1;
                b[idx(i,j)] = "diag";
            }
            else if (c[idx(i-1,j)] >= c[idx(i,j-1)]) {
                c[idx(i,j)] = c[idx(i-1,j)];
                b[idx(i,j)] = "up";
            }
            else {
                c[idx(i,j)] = c[idx(i,j-1)];
                b[idx(i,j)] = "left";
            }
        }
    }

    
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            std::cout << c[idx(i,j)] << " ";
        }
        std::cout << std::endl;
    }

    print_lcs(b, X, m, n);    
    std::cout << "result: " << result << std::endl;

}
