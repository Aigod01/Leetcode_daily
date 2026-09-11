class Solution {
public:

    struct Node {
        Node* child[2];

        Node() {
            child[0] = NULL;
            child[1] = NULL;
        }
    };

    void insert(Node* root, int num) {
        Node* curr = root;

        for(int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(curr->child[bit] == NULL) {
                curr->child[bit] = new Node();
            }

            curr = curr->child[bit];
        }
    }

    int getMaxXor(Node* root, int num) {
        Node* curr = root;
        int ans = 0;

        for(int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;

            if(curr->child[opposite] != NULL) {
                ans |= (1 << i);
                curr = curr->child[opposite];
            }
            else {
                curr = curr->child[bit];
            }
        }

        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        vector<array<int,3>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i][1], queries[i][0], i});
        }

        sort(q.begin(), q.end());

        vector<int> answer(queries.size(), -1);

        Node* root = new Node();

        int j = 0;

        for(auto query : q) {

            int m = query[0];
            int x = query[1];
            int index = query[2];

            while(j < nums.size() && nums[j] <= m) {
                insert(root, nums[j]);
                j++;
            }

            if(j > 0) {
                answer[index] = getMaxXor(root, x);
            }
        }

        return answer;
    }
};
