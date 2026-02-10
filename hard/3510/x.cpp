#include "../../timer.h"

class Solution {
public:
    ListNode* build(vector<int>& nums) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        for (int x : nums) {
            curr->next = new ListNode(x);
            curr = curr->next;
        }
        return dummy.next;
    }
    int minimumPairRemoval(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        int ic = 0;
        vector<int> next(n);
        vector<int> prev(n);
        vector<long> lnums(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            next[i] = i + 1;
            prev[i] = i - 1;
        }
        auto comp = [](const pair<long, int>& a, const pair<long, int>& b) {
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        };
        set<pair<long, int>, decltype(comp)> pairs(comp);

        for (int i = 0; i < n - 1; i++){
            pairs.insert({(long)nums[i] + nums[i + 1], i});
            if (nums[i + 1] < nums[i]) ic++;
        }
        while(ic){
            ans++;
            auto small = pairSums.extract(pairSums.begin()).value();
            const auto& [pairSum, currIndex] = small.value();
            const int n = next[currIndex], p = prev[currIndex];
            if (prevIndex >= 0) {
                const long oldPairSum = values[prevIndex] + values[currIndex];
                const long newPairSum = values[prevIndex] + pairSum;
                pairSums.erase({oldPairSum, prevIndex});
                pairSums.insert({newPairSum, prevIndex});

                if (values[prevIndex] > values[currIndex]) --inversionsCount;
                if (values[prevIndex] > pairSum) ++inversionsCount;
            }
        }
        return ans;
    }
};

struct token {
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minimumPairRemoval(data.nums);
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
    tokens[0] = {{5, 2, 3, 1}, 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}