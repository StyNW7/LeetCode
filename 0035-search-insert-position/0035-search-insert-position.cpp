class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int ans = 0;
        for (int i = 0; i < size; i++){
            if (nums[i] == target){
                return i;
            }
            else if (nums[i] < target) ans++;
            else break;
        }
        return ans;
    }
};