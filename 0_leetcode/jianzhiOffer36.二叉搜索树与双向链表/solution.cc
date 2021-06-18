// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
	Node* treeToDoublyList(Node* root) {
    if (!root) return head;

    inorder_travesal(root);	
    pre->right = head;
    head->left = pre;
    return head;
	}

private:
	Node *pre = nullptr;
	Node *head = nullptr;	

	void inorder_travesal(Node *cur)
  {
    if (!cur) return;

    inorder_travesal(cur->left);

    if (!pre) head = cur;
    else pre->right = cur;
    cur->left = pre;
    pre = cur;

    inorder_travesal(cur->right);
  }
};
