#include <iostream>
using namespace std;

class BinaryTree
{
	struct TreeNode
	{
		TreeNode *left;
		TreeNode *right;
		int val;
		TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
	};

      public:
	BinaryTree()
	{
		root = nullptr;
	}

	bool insert(int val)
	{
		TreeNode *newNode = new TreeNode(val);
		if (!root)
		{
			root = newNode;
			return true;
		}
		else
		{
			TreeNode *pos = root;
			while (pos)
			{
				if (newNode->val == pos->val)
				{
					return false;
				}
				if (newNode->val > pos->val)
				{
					if (pos->right)
					{
						pos = pos->right;
					}
					else
					{
						pos->right = newNode;
						return true;
					}
				}
				else
				{
					if (pos->left)
					{
						pos = pos->left;
					}
					else
					{
						pos->left = newNode;
						return true;
					}
				}
			}
		}
		return false;
	}

	void inorderPrint(TreeNode *pos)
	{
		if (!pos)
		{
			return;
		}
		inorderPrint(pos->left);
		cout << pos->val << " " << endl;
		inorderPrint(pos->right);
	}

	TreeNode *getRoot()
	{
		return root;
	}

	TreeNode *recurTraversal(TreeNode *pos, int val)
	{
		if (!pos)
		{
			return nullptr;
		}
		if (pos->val == val)
		{
			return pos;
		}
		else if (val < pos->val)
		{
			return recurTraversal(pos->left, val);
		}
		else
		{
			return recurTraversal(pos->right, val);
		}
	}

	TreeNode *get(int val)
	{
		return recurTraversal(root, val);
	}

	int getFarRight(TreeNode *pos)
	{
		int res = -1;
		while (pos->right)
		{
			res = pos->val;
			pos = pos->right;
		}
		return res;
	}

	bool remove(int val)
	{
		TreeNode *node = get(val);
		if (!node)
		{
			return false;
		}
		if (!node->left)
		{
			node = node->right;
			return true;
		}
		else if (!node->right)
		{
			node = node->left;
			return true;
		}
		else
		{
			int rightVal = getFarRight(node->left);
			if (rightVal == -1)
			{
				node->val = node->left->val;
				node->left = nullptr;
			}
			else
			{
				node->val = rightVal;
			}
			return true;
		}
	}

      private:
	TreeNode *root;
};

int main()
{
	BinaryTree binTree;
	binTree.insert(5);
	binTree.insert(2);
	binTree.insert(3);
	binTree.insert(6);
	binTree.insert(6);
	binTree.insert(1);
	binTree.insert(4);
	binTree.insert(7);
	binTree.inorderPrint(binTree.getRoot());
	cout << endl;
	binTree.remove(2);
	binTree.inorderPrint(binTree.getRoot());
	cout << endl;
	binTree.remove(7);
	binTree.inorderPrint(binTree.getRoot());
	cout << endl;
	return 0;
}
