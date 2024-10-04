class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 0);

        long long mul = 1;
        int zero = 0;
        int zeroIdx = 1;
        for(int i = 0; i < nums.size();i++){
            long long n = nums[i];
            if(n == 0){
                zero++;
                zeroIdx = i;
                if(zero>=2){
                    return answer;
                }
            }
            else{
                mul *= n;
                mul %= 2147483647;
            }
        }
        if(zero){
            answer[zeroIdx] = mul;
            return answer;
        }
        for(int i = 0; i < nums.size(); i++){
            answer[i] = mul/nums[i];
        }
        return answer;
    }
};