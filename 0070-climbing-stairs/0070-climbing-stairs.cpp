class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        if (n == 0) return 0;
        if (n == 1) return 1;

        int total;
        
        for (int i = 2; i <= n; i++){
            total = a + b;
            b = a;
            a = total;
        }

        return total;

    }
};