class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.size(), len2 = s2.size();
        int idx2 = 0, cycleCnt = 0, cnt1 = 0;
        unordered_map<int, pair<int, int>> mp;
        while (cnt1 < n1) {
            for (int i = 0; i < len1; ++i) {
                if (s1[i] == s2[idx2]) {
                    idx2++;
                    if (idx2 == len2) {
                        idx2 = 0;
                        cycleCnt++;
                    }
                }
            }
            cnt1++;
            if (mp.count(idx2)) {
                auto [prevCycleCnt, prevCnt1] = mp[idx2];
                int cycleLen = cycleCnt - prevCycleCnt, cnt1Len = cnt1 - prevCnt1;
                int cycleNum = (n1 - prevCnt1) / cnt1Len;
                cycleCnt = prevCycleCnt + cycleNum * cycleLen;
                cnt1 = prevCnt1 + cycleNum * cnt1Len;
            } else {
                mp[idx2] = { cycleCnt, cnt1 };
            }
        }
        return cycleCnt / n2;
    }
};
