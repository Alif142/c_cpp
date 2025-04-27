#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> findPaths(TreeNode* root1) {
        vector<string> result;
        if (root1) {
            explore(root1, "", result);
        }
        return result;
    }

private:
    void explore(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;

        path += to_string(node->value);

        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }

        path += "->";
        explore(node->left, path, result);
        explore(node->right, path, result);
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(5);

    Solution s1;
    vector<string> paths1 = s1.findPaths(root1);

    for (const auto& path : paths1) {
        cout << path << endl;
    }

    delete root1->left->right;
    delete root1->left;
    delete root1->right;
    delete root1;
    
    TreeNode* root2 = new TreeNode(1);
    Solution s2;
    vector<string> paths2 = s1.findPaths(root2);

    for (const auto& path : paths2) {
        cout << path << endl;
    }

    delete root2;
    return 0;
}

