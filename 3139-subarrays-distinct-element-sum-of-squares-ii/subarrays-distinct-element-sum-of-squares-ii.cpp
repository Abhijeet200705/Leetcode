
// class Solution {
//     static const int MOD = 1e9 + 7;

//     long long sum[400005] = {};
//     long long sq[400005] = {};
//     long long lazy[400005] = {};

//     void push(int node, int l, int r) {
//         if (lazy[node] == 0 || l == r) return;

//         int mid = (l + r) / 2;
//         int left = node * 2, right = left + 1;

//         for (int child : {left, right}) {
//             int len = (child == left) ? mid - l + 1 : r - mid;
//             long long d = lazy[node];

//             sq[child] = (sq[child] + 2 * d * sum[child]
//                          + d * d % MOD * len) % MOD;

//             sum[child] = (sum[child] + d * len) % MOD;
//             lazy[child] += d;
//         }

//         lazy[node] = 0;
//     }

//     void update(int node, int l, int r, int ql, int qr) {
//         if (ql > r || qr < l) return;

//         if (ql <= l && r <= qr) {
//             int len = r - l + 1;

//             sq[node] = (sq[node] + 2 * sum[node]
//                         + len) % MOD;

//             sum[node] = (sum[node] + len) % MOD;
//             lazy[node]++;
//             return;
//         }

//         push(node, l, r);

//         int mid = (l + r) / 2;

//         update(node * 2, l, mid, ql, qr);
//         update(node * 2 + 1, mid + 1, r, ql, qr);

//         sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
//         sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
//     }

// public:
//     int sumCounts(vector<int>& nums) {
//         int n = nums.size();

//         fill(sum, sum + 4 * n + 5, 0);
//         fill(sq, sq + 4 * n + 5, 0);
//         fill(lazy, lazy + 4 * n + 5, 0);

//         vector<int> last(100001, -1);
//         long long ans = 0;

//         for (int i = 0; i < n; i++) {
//             int prev = last[nums[i]];

//             update(1, 0, n - 1, prev + 1, i);

//             ans = (ans + sq[1]) % MOD;
//             last[nums[i]] = i;
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> cnt(n + 1), tot(n + 1);  // Fenwick trees over previous-copy positions, stored right to left
        unordered_map<int, int> last;
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            int p = last.count(nums[r]) ? last[nums[r]] : -1;
            long long c = 0, s = 0;
            for (int i = n - p - 1; i > 0; i -= i & -i)  // boxes 1..n-p-1 hold the positions > p
                c += cnt[i], s += tot[i];
            long long gain = (long long)(r - p) * (r - p) - 2 * (s - p * c);  // at most 1e10
            ans = (ans + (n - r) * gain) % MOD;
            for (int i = n - p; i <= n; i += i & -i)  // insert p; p = -1 lands past the end and is skipped
                cnt[i]++, tot[i] += p;
            last[nums[r]] = r;
        }
        return ans;
    }
};