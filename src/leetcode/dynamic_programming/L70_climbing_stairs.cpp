#include <iostream>
#include <vector>

class ClimbingStairs {
    // O(2^n)
private:
    int climbStairs(int i, int n) {
        if (i > n) {
            return 0;
        }
        
        if (i == n) {
            return 1;
        }
        return climbStairs(i + 1, n) + climbStairs(i + 2, n);
    }

public:
    int climb(int n) {
        climbStairs(0, n);
    }
};


class ClimbingStairsWithMemory {
    // O(n)
private:
    int climbStairs(int i, int n, std::vector<int>& memo) {
        if(i > n) return 0;
        if(i == n) return 1;
        if(memo[i] > 0) return memo[i];

        memo[i] = climbStairs(i + 1, n, memo) + climbStairs(i + 2, n, memo);
        return memo[i];
    }
public:
    int climb(int n) {
        std::vector<int> memo(n + 1, 0);
        return climbStairs(0, n, memo);
    }

    int climbWithoutRecursion(int n) {
        
        if (n == 1) {
            return 1;
        }

        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        } 
        return dp[n];
    }
};

