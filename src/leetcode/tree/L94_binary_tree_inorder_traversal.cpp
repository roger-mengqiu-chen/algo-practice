#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
private:
    void travel(TreeNode* n, vector<int>& v) {
        if(!n) return;
        travel(n->left, v);
        v.push_back(n->val);
        travel(n->right, v);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        travel(root, v);
    }

    vector<int> inorderTraversalWithoutRecursion(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        TreeNode* pre;

        while(curr != nullptr) {
            if(curr->left == nullptr) {
                res.push_back(curr->val);
                curr = curr->right;
            }
            else {
                pre = curr->left;

                while(pre->right != nullptr) {
                    pre = pre->right;
                }

                pre->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
        }
        return res;
    }
};