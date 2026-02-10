#include "../../timer.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        const int half = (n1 + n2 + 1)/2;
        int l = 0, r = n1;
        while(l <= r){
            const int d1 = (l + r) / 2;
            const int d2 = half - d1;
            int mx1 = d1 == 0 ? INT_MIN : nums1[d1 - 1];
            int mx2 = d2 == 0 ? INT_MIN : nums2[d2 - 1];
            int mn1 = d1 == n1 ? INT_MAX : nums1[d1];
            int mn2 = d2 == n2 ? INT_MAX : nums2[d2];
            if(mx1 <= mn2 && mx2 <= mn1){
                if((n1 + n2) % 2 == 0){
                    return (max(mx1, mx2) + min(mn1, mn2)) * 0.5;
                } else {
                    return max(mx1, mx2);
                }
            } else if (mx1 <= mn2){
                l = d1 + 1;
            } else {
                r = d1 - 1;
            }
        }
        return 0;
    }
};


struct token {
    vector<int> nums1;
    vector<int> nums2;
    double ans;
    double res;
};

void handle(token& data){
    Solution s;
    data.res = s.findMedianSortedArrays(data.nums1, data.nums2);
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
    const int n = 2;
    vector<token> tokens(n);
    tokens[0] = {{1, 3}, {2}, 2};
    tokens[1] = {{1, 2}, {3, 4}, 2.5};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}