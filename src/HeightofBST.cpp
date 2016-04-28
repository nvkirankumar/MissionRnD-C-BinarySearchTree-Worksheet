/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int get_height(struct node *root){
	int h1, h2;
	if (root == NULL)
		return 0;
	else{
		h1 = (1 + get_height(root->left));
		h2 = (1 + get_height(root->right));
	}
	return (h1>h2)?(h1):(h2);
}

int leftsum(struct node *root)
{
	int sum;
	if (root == NULL)
		return 0;
	else
		sum = (root->data + leftsum(root->left));
	return sum;
}
int get_left_subtree_sum(struct node *root){
	 return leftsum(root->left);
}

int rightsum(struct node *root)
{
	int sum;
	if (root == NULL)
		return 0;
	else
		sum = (root->data + rightsum(root->right));
	return sum;
}
int get_right_subtree_sum(struct node *root){
	return rightsum(root->right);
}

