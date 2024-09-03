class Solution {
public:

    bool canJump(vector<int>& nums) {
        int f = 0, c = 0;
        if (nums.size() == 1) return 1;
        for (int i = nums.size()-2; i >= 0; i--){
            if (nums[i] == 0) f = 1;

            if (f) {
                c++;
                if (nums[i] >= c){
                    f = 0;
                    c = 0;
                }
            }
        }
        if (f) return 0;
        else return 1;
    }

};