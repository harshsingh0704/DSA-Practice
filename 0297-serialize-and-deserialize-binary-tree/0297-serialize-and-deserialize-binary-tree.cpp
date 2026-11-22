
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                s += "#,";
            }
            else {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            getline(ss, str, ',');

            if (str != "#") {
                TreeNode* left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left);
            }

            // Right child
            getline(ss, str, ',');

            if (str != "#") {
                TreeNode* right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }
        }

        return root;
    }
};
