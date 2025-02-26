class Solution {
    public:
        vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<int> res;
            for (int i = 0; i <= k && i <= nums1.size(); ++i) {
                if (k - i > nums2.size())
                    continue;
                auto n1 = maxnum(nums1, i);
                auto n2 = maxnum(nums2, k-i);
                auto cur = merge(n1, n2, k);
                res = max(res, cur);
            }
            return res;
        }
    
    private:
        vector<int> maxnum(vector<int>& nums, int k) {
            vector<int> res;
            res.reserve(k);
            for (int i = 0; i < nums.size(); ++i) {
                while (!res.empty() && res.back() < nums[i] && nums.size() + res.size() - i > k)
                    res.pop_back();
                if (res.size() < k)
                    res.push_back(nums[i]);
            }
            return res;
        }
    
        vector<int> merge(vector<int>& n1, vector<int>& n2, int k) {
            vector<int> res;
            res.reserve(k);
    
            int i = 0, j = 0;
            while (i < n1.size() && j < n2.size()) {
                if (n2[j] > n1[i]) {
                    res.push_back(n2[j++]);
                } else if (n2[j] == n1[i]) {
                    int i1 = i, j1 = j;
                    while (i1 < n1.size() && j1 < n2.size() && n1[i1] == n2[j1]) {
                        ++i1;
                        ++j1;
                    }
                    if (j1 == n2.size() || (i1 < n1.size() && n1[i1] > n2[j1])) {
                        res.push_back(n1[i++]);
                    } else {
                        res.push_back(n2[j++]);
                    }
                } else {
                    res.push_back(n1[i++]);
                }
            }
            copy(n1.begin() + i, n1.end(), back_inserter(res));
            copy(n2.begin() + j, n2.end(), back_inserter(res));
            return res;
        }
    };
