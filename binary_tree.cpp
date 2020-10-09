#include<bits/stdc++.h>
#include<queue>
using namespace std;
class node {
	public:
		int data;
	public:
		node *left;
		node *right;
		node(int x = 0) {
			this->data = x;
		}
	void insert();
	void inorder(node*);
	node*  deletion(node* , int) ;
	void delet_deepest(node* , node*);
};
void node :: insert()
{
	queue<node *> q;
	q.push(this);
	while(!q.empty()) {
		node *temp = q.front();
		q.pop();
		cout<<"enter the left data of "<<temp->data<<"or -1 for stop"<<endl;
		int data1;
		cin>>data1;
		cout<<"enter the right data of "<<temp->data<<"or -1 for stop"<<endl;
		int data2;
		cin>>data2;
		if(data1 != -1) {
			temp->left = new node(data1);
			q.push(temp->left);
		}
		if(data2 != -1) {
			temp->right = new node(data2);
			q.push(temp->right);
		}
	}
	return ;
}
void node :: inorder(node *temp)
{
    if (!temp)
        return;

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}
void node :: delet_deepest(node *root , node *d_node)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		node* temp = q.front();
		q.pop();
		if(temp == d_node) {
			temp = NULL;
			delete d_node;
			return ;
		}
		if(temp->left) {
			if(temp->left == d_node) {
				temp->left = NULL;
				delete d_node;
				return ;
			}
			else
				q.push(temp->left);
		}
		if(temp->right) {
                        if(temp->right == d_node) {
                                temp->right = NULL;
                                delete d_node;
                                return ;
                        }
                        else
                                q.push(temp->right);
                }

	}
}
node* node :: deletion(node* root , int key) {
	if(root == NULL)
		return NULL;
	if(root->left == NULL && root->right == NULL) {
		if(root->data == key)
			return NULL;
		else
			return root;
	}
	node *temp = NULL;
	queue<node*> q;
	node* key_node = NULL;
	q.push(root);
	while(!q.empty()) {
		temp = q.front();
		q.pop();
		if(temp->data == key)
			key_node = temp;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	if(key_node) {
		int x = temp->data;
		delet_deepest(root , temp);
		key_node->data = x;
	}
	return root;
}
int main()
{
	int choice,data;
	node *root1;
	cout<<"enter the data"<<endl;
	cin>>data;
	node *root = new node(data);	
	//insertion of data
	root->insert();
	root->inorder(root);
	// deletion of data;
	cout<<"enter the data to be deleted"<<endl;
	cin>>data;
	root->deletion(root,data);
	root->inorder(root);	
}
