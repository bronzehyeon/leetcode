class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> v;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < N; i++){
            if(nums[i] > 0){
                break;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        auto iter = s.begin();
        while(iter != s.end()){
            v.push_back(*iter);
            iter++;
        }
        return v;
    }
};