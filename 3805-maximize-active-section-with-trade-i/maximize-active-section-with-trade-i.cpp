class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initialOnes = 0;
        for (char c : s) {
            if (c == '1') initialOnes++;
        }

        // Augment the string
        string t = "1" + s + "1";

        vector<pair<char, int>> runs;

        // Run Length Encoding
        for (char c : t) {
            if (runs.empty() || runs.back().first != c) {
                runs.push_back({c, 1});
            } else {
                runs.back().second++;
            }
        }

        int maxGain = 0;

        // Look for: 0-run, 1-run, 0-run
        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                int leftZeros = runs[i - 1].second;
                int rightZeros = runs[i + 1].second;

                maxGain = max(maxGain, leftZeros + rightZeros);
            }
        }

        return initialOnes + maxGain;
    }
};