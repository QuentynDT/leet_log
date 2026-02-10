#include "../../timer.h"

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        static constexpr int kMod = 1'000'000'007;
        const int n1 = nums1.size(), n2 = nums2.size();
        int i1 = 0, i2 = 0;
        long long sum1 = 0, sum2 = 0, ans = 0;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] < nums2[i2]){
                sum1+=nums1[i1++];
            } else if (nums1[i1] > nums2[i2]){
                sum2+=nums2[i2++];
            } else {
                ans = (ans + max(sum1, sum2) + nums1[i1]) % kMod;
                sum1 = 0, sum2 = 0;
                i1++;
                i2++;
            }
        }
        while(i1 < n1){
            sum1 += nums1[i1++];
        }
        while(i2 < n2){
            sum2 += nums2[i2++];
        }
        ans += max(sum1, sum2);
        return ans % kMod;
    }
};

struct token {
    vector<int> nums1;
    vector<int> nums2;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxSum(data.nums1, data.nums2);
}

void runTests(vector<token>& tokens){
    cout << '\n';
    for(token& t : tokens){
        handle(t);
        cout << "Output: ";
        display(t.res);
        cout << "\nExpected: ";
        display(t.ans);
        cout << "\n\n";
    }
}

int main(){
    const int n = 3;
    vector<token> tokens(n);
    tokens[0] = {{2,4,5,8,10}, {4,6,8,9}, 30};
    tokens[1] = {{1,3,5,7,9}, {3,5,100}, 109};
    tokens[2] = {{1,2,3,4,5}, {6,7,8,9,10}, 40};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}