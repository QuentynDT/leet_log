#include "../../timer.h"
struct TrieNode{
    vector<shared_ptr<TrieNode>> children;
    TrieNode() : children(2) {}
};
class BitTrie{
public:
    BitTrie(int maxBit) : maxBit(maxBit) {}
    void insert(int num){
        shared_ptr<TrieNode> node = root;
        for(int i = maxBit; i >= 0; i--){
            int bit = num >> i & 1;
            if(node -> children[bit] == nullptr){
                node -> children[bit] = make_shared<TrieNode>();
            }
            node = node -> children[bit];
        }
    }
    int getMaxXor(int num){
        int maxXor = 0;
        shared_ptr<TrieNode> node = root;
        for(int i = maxBit; i >= 0; i--){
            int bit = num >> i & 1;
            int anti = bit ^ 1;
            if(node -> children[anti]){
                maxXor = maxXor | 1 << i;
                node = node -> children[anti];
            } else if (node -> children[bit]){
                node = node -> children[bit];
            } else {
                return 0;
            }
        }
        return maxXor;
    }
private:
    const int maxBit;
    shared_ptr<TrieNode> root = make_shared<TrieNode>();
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        const int mx = ranges::max(nums);
        if(mx == 0) return 0;
        const int mb = 31 - __builtin_clz(mx);
        int ans = 0;
        BitTrie bitTrie(mb);
        for (const int num : nums) {
            ans = max(ans, bitTrie.getMaxXor(num));
            bitTrie.insert(num);
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
    data.res = s.findMaximumXOR(data.nums);
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
    tokens[0] = {{3,10,5,25,2,8}, 28};
    tokens[1] = {{14,70,53,83,49,91,36,80,92,51,66,70}, 127};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}