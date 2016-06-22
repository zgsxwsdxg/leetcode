struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class SolutionfilpUpsideDown {
    public:
        TreeNode* filpUpsideDown(TreeNode* root) {
            if (root == NULL) return NULL;
            if (root->left == NULL) return root;
            TreeNode* newroot = filpUpsideDown(root->left);
            root->left->left = root->right;
            root->left->right = root;
            root->left = NULL;
            root->right = NULL;
            return newroot;
        }
};

class SolutionfilpUpsideDown {
    public:
        TreeNode* filpUpsideDown(TreeNode* root) {
            if (root == NULL) return NULL;
            if (root->left == NULL) return root;
            stack<TreeNode*> st;
            while (root->left){
                st.push(root);
                root = root->left;
            }
            TreeNode* pre = root;
            while (!st.empty()){
                TreeNode* p = st.top();
                st.pop();
                pre->left = p->right;
                pre->right = p;
                pre = p;
            }
            pre->left = NULL;
            pre->right = NULL;
            return root;
        }
};

class SolutionfilpUpsideDown {
    public:
        TreeNode* filpUpsideDown(TreeNode* root) {
            if (root == NULL) return NULL;
            if (root->left == NULL) return root;
            TreeNode* node = root, *parent= NULL, *right = NULL;
            while (node){
                TreeNode* left = node->left;
                node->left = right;
                right = node->right;
                node->right = parent;
                parent = node;
                node = left;
            }
            return parent;
        }
};
