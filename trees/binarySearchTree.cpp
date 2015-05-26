# include <iostream>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
};

class BSTree
{
	private:
		node *root;
		void insertVal(node**,int);
		void inOrderTraversal(node*);
		void preOrderTraversal(node*);
		void postOrderTraversal(node*);
	public:
		BSTree()
		{
			root=NULL;
		}

		void insert(int);
		
		void inOrder();
		void preOrder();
		void postOrder();
		void display();
		
};


void BSTree::insert(int x)
{	
	insertVal(&root,x);
}

void BSTree::insertVal(node **tmp,int x)
{
	if(*tmp==NULL)
	{
		*tmp= new node;
		(*tmp)->val=x;
		(*tmp)->left=NULL;
		(*tmp)->right=NULL;
		return;
	}
	else
	{
		if(x<(*tmp)->val)
			insertVal(&((*tmp)->left),x);
		else
			insertVal(&((*tmp)->right),x);
	}
	return;
}

void BSTree::inOrderTraversal(node *tmp)
{
	if(tmp!=NULL)
	{
		inOrderTraversal(tmp->left);
		cout<<tmp->val<<",";
		inOrderTraversal(tmp->right);
	}
}

void BSTree::inOrder()
{
	inOrderTraversal(root);
}

void BSTree::preOrderTraversal(node *tmp)
{
	if(tmp!=NULL)
	{
		cout<<tmp->val<<",";
		preOrderTraversal(tmp->left);
		preOrderTraversal(tmp->right);
	}
}
void BSTree::preOrder()
{
	preOrderTraversal(root);
}

void BSTree::postOrderTraversal(node *tmp)
{
	if(tmp!=NULL)
	{
		postOrderTraversal(tmp->left);
		postOrderTraversal(tmp->right);
		cout<<tmp->val<<",";
	}
}
void BSTree::postOrder()
{
	postOrderTraversal(root);
}


void BSTree::display()
{	
	cout<<root<<","<<root->right<<","<<root->left;
}

int main()
{
	BSTree bt;
	bt.insert(56);
	bt.insert(90);
	bt.insert(80);
	bt.insert(45);
	bt.inOrder(); cout<<endl;	
	bt.postOrder(); cout<<endl;
	bt.preOrder();	cout<<endl;
}
