#include<iostream>

using namespace std;

class tree
{
private:
	struct node;
	typedef struct node tree_node;

	tree_node* head;

	struct node{
	public:
		int data;
		tree_node* left;
		tree_node* right;

		node():data(0),left(NULL),right(NULL){}
	};

	
private://methods
 
	/*Create a tree of level order */
	tree_node* _create_tree(int arr[], int index, int elements)
	{
		if (index >= elements) 
			return NULL;

		tree_node* nod = new node();
	
		nod->data  = arr[index];
		nod->left  = _create_tree(arr, 2*index + 1, elements);
		nod->right = _create_tree(arr, 2*index + 2, elements);

		return nod;
	}

 
	/* Print nodes at a given level */
	void printGivenLevel(tree_node* root, int level)
	{
  		if(root == NULL)
    			return;
		if(level == 1)
			cout << root->data ;
		else if (level > 1)
		{
			printGivenLevel(root->left, level-1);
			printGivenLevel(root->right, level-1);
		}
	}

	/* Height of a tree */
	int height(tree_node* node)
	{
		if (node==NULL)
			return 0;
		else
		{
     			/* compute the height of each subtree */
			int lheight = height(node->left);
			int rheight = height(node->right);
 
			/* use the larger one */
			if (lheight > rheight)
				return(lheight+1);
			else 
				return(rheight+1);
		}
	} 

	/* PreOrder tree traversal */
	void _preOrder(tree_node* root)
	{
		if(root)
		{
			cout << root->data ;
			_preOrder(root->left);
			_preOrder(root->right);
		}
	}

	/* inOrder tree traversal */
	void _inOrder(tree_node* root)
	{
		if(root)
		{
			_inOrder(root->left);
			cout << root->data ;
			_inOrder(root->right);
		}
	}

	/* postOrder tree traversal */
	void _postOrder(tree_node* root)
	{
		if(root)
		{
			_postOrder(root->left);
			_postOrder(root->right);
			cout << root->data ;
		}
	}



public:
	tree():head(NULL){}	
	
	void preOrder()
	{
		cout << "PreOrder: ";
		_preOrder(head);
	}

	void inOrder()
	{
		cout << "inOrder: ";
		_inOrder(head);
	}
	void postOrder()
	{
		cout << "postOrder: ";
		_postOrder(head);
	}



	/* Function to print level order traversal a tree*/
	void printLevelOrder()
	{
		int h = height(head);
		cout << "height" << h << endl;

		for(int i=1; i<=h; i++)
			printGivenLevel(head, i);
	}     

	tree_node* create_tree(int arr[],int n)
	{
		tree_node* root = new node();
		head = root;	
	
		int index = 0;
		root->data  = arr[0];
		root->left  = _create_tree(arr, 2*index + 1, n);
		root->right = _create_tree(arr, 2*index + 2, n);
	
	}

};

int main()
{

	int arr[] = {1,2,3,4,5,6,7};
	tree t1;
	t1.create_tree(arr,7);
	t1.printLevelOrder();
	cout << endl;
	t1.preOrder();
	cout << endl;
	t1.inOrder();
	cout << endl;
	t1.postOrder();
	cout << endl;

	return 0;
}

