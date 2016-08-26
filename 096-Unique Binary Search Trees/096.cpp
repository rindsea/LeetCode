﻿#include <iostream>
#include <vector>
using namespace std;
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example,
Given n = 3, there are a total of 5 unique BST's. 
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        if (n == 0)
            return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= i; ++j)
                dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp.back();
    }
};
int main()
{  
    Solution s;
    cout << s.numTrees(3) << endl;
    system("pause");
    return 0;
}
