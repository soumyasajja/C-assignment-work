#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
class BST
{
	struct node *start;
public:
	BST();
	void* Insert(int,struct node *);
	void Delete_ele(int);
	void Inorder();
	void Preorder();
	void Postorder();
	~BST();
	int FindMax(struct node *);
	int FindMin(struct node *);
	int height(struct node *);
	int NLN(struct node *);
	int NNLN(struct node *);
	friend print(struct node *);
	friend delete_node(struct node*);
};
BST::BST()
{
	start = NULL;
}
void* BST::Insert(int ele,struct node *curr)
{
	if (curr == NULL)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->left = NULL;
		return temp;
	}
	else
	{
		if (ele < curr->data)
			curr->left = Insert(ele, curr->left);
		else
			curr->right = Insert(ele, curr->right);
		return curr;
	}
}
int BST::FindMin(struct node *curr)
{
	if (curr != NULL)
	{
		while (curr->left != NULL)
			curr = curr->left;
		return(curr->data);
	}
	return -1;
}
int BST::FindMax(struct node *curr)
{
	if (curr != NULL)
	{
		while (curr->right != NULL)
			curr = curr->right;
		return(curr->data);
	}
	return -1;
}
void* BST::Delete_ele(int ele, struct node *curr)
{
	if (curr != NULL)
	{
		if (ele > curr->data)
			curr - right = delete_ele(ele, curr->right);
		else
			if (ele < curr->data)
				curr->left = Delete_ele(ele, curr->left);
			else
			{
				if (curr->left != NULL && curr->right != NULL)
				{
					curr->data = FindMax(curr->left);
					curr->left = Delete_ele(curr->data, curr->left);
				}
				else
				{
					struct node *temp;
					temp = curr;
					if (curr->left == NULL)
						return 0;
					curr = curr->right;
					else
						curr = curr->left;
					delete temp;
				}
				return curr;
			}
	}
}
int BST::NLN(struct node *curr)
{
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 1;
	return(NLN(curr->left) + (NLN(curr->right)));
}
int BST::NNLN(struct node *curr)
{
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 0;
	return(NNLN(curr->left) + NNLN(curr->right) + 1);
}
int BST::height(struct node *curr)
{
	if (curr == NULL)
		return -1;
	else
		return (max(height(curr->left), height(curr->right) + 1);
}
void Inorder()
{
	if (start == NULL)
		print(start);
}
print(struct node *curr)
{
	if (curr != NULL)
	{
		print(curr->left);
		cout << curr->data;
		print(curr->right);
	}
}
void BST::Preorder()
{
	if (start == NULL)
		print(start);
}
BST::~BST()
{
	if (start != NULL)
		delete_node(start);
}
delete_node(struct node *curr)
{
	if (curr != NULL)
	{
		delete_node(curr->left);
		delete_node(curr->right);
		delete curr;
	}
}