class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        vector<long long> plus(N);
        vector<long long> minus(N);
        plus[0] = max(0,nums[0]);
        minus[0] = min(0,nums[0]);
        long long answer = nums[0];
        for(int i = 1; i < N; i++){
            long long n = nums[i];
            if(n > 0){
                if(plus[i-1] == 0){
                    plus[i] = n;
                }
                else{
                    plus[i] = plus[i-1] * n;
                }
                minus[i] = minus[i-1] * n;
            }
            else if(n < 0){
                plus[i] = minus[i-1] * n;
                if(plus[i-1] == 0){
                    minus[i] = n;
                }
                else{
                    minus[i] = plus[i-1] * n;
                }
                
            }
            else{
                plus[i] = 0;
                minus[i] = 0;
            }
            plus[i]%=2147483647;
            minus[i]%=2147483647;
            answer = max(answer, plus[i]);
        }
        return answer;
    }
};