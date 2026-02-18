#include "../../timer.h"

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            if(i % 2 == 0){
                if(nums[i] > nums[i + 1]){
                    swap(nums[i], nums[i + 1]);
                }
            } else {
                if(nums[i] < nums[i + 1]){
                    swap(nums[i], nums[i + 1]);
                }
            }
            
        }
        return;
    }
};

struct token {
    vector<int> nums;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    s.wiggleSort(data.nums);
    data.res = data.nums;
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
    const int n = 1;
    vector<token> tokens(n);
    tokens[0] = {{1,1,1,5,6,4}, {1,6,1,5,1,4}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}