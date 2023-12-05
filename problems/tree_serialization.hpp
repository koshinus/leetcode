#pragma once

#include <vector>
#include <string>
#include <sstream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
    void serializeNode(std::stringstream& output, TreeNode* node)
    {
        if (!node)
        {
            output << ",1001";
            return;
        }
        output << ',' << std::to_string(node->val);
        serializeNode(output, node->left);
        serializeNode(output, node->right);
    }

    std::vector<int> parseData(std::string data)
    {
        std::vector<int> vect;
        std::stringstream ss(data);
        for (int i; ss >> i;)
        {
            vect.push_back(i);
            if (ss.peek() == ',')
                ss.ignore();
        }
        return vect;
    }

    void deserializeNodes(const std::vector<int>& nodes, int i, TreeNode* cur_node)
    {
        if (i >= nodes.size())
            return;
        int val = nodes[i];
        if (val == 1001)
        {
            cur_node = nullptr;
            return;
        }
        cur_node->val = val;
        cur_node->left = new TreeNode(0);
        cur_node->right = new TreeNode(0);
        deserializeNodes(nodes, 2 * i + 1, cur_node->left);
        deserializeNodes(nodes, 2 * i + 1, cur_node->right);
    }
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root)
    {
        std::stringstream s;
        serializeNode(s, root);
        return s.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data)
    {
        auto vec = parseData(data);
        auto root = new TreeNode(0);
        deserializeNodes(vec, 0, root);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

namespace tree_seria
{

    void run_tests()
    {
        TreeNode* root;
        Codec ser, deser;
        TreeNode* ans = deser.deserialize(ser.serialize(root));
    }

}