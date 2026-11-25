class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        const long long BASE = 1000003, MOD = 1000000007;
        int n = nums.size();
        vector<long long> h(n + 1, 0), p(n + 1, 1);
        for (int i = 0; i < n; i++) {
            long long x = ((nums[i] % MOD) + MOD) % MOD;
            h[i + 1] = (h[i] * BASE + x) % MOD;
            p[i + 1] = (p[i] * BASE) % MOD;
        }
        auto check = [&](int len) {
            unordered_map<long long, int> cnt;
            for (int i = 0; i <= n - len; i++) {
                long long val = (h[i + len] - (h[i] * p[len]) % MOD + MOD) % MOD;
                cnt[val]++;
            }
            for (auto& [k, v] : cnt) {
                if (v == 1) return true;
            }
            return false;
        };
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};