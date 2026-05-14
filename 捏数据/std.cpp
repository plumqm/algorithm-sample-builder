#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int r;
    cin >> r;
    
    // 读入数字金字塔
    vector<vector<int>> pyramid(r, vector<int>(r, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> pyramid[i][j];
        }
    }
    
    // dp[i][j] 表示从顶部到 (i,j) 的最大路径和
    // 直接在原数组上修改，从下往上递推
    for (int i = r - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            // 可以选择左下或右下，取最大值
            pyramid[i][j] += max(pyramid[i+1][j], pyramid[i+1][j+1]);
        }
    }
    
    // 答案在顶部
    cout << pyramid[0][0] << endl;
    
    return 0;
}