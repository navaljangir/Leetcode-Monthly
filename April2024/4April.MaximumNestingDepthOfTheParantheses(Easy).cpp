class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int ans = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
                if (ans < count)
                    ans = count;
            } else if (c == ')') {
                count--;
            }
        }
        return ans;
    }
};
