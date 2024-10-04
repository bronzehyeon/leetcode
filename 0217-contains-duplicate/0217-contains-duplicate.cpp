class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            if(m[n]){
                return true;
            }
            m[n] = 1;
        }
        return false;
    }
};