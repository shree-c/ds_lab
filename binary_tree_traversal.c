#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} node;

node *new_node(int data) {
	node *hold = (node *) malloc(sizeof(node));
	hold->data = data;
	return hold;
}
node *insert(node *root, int data) {
	if (root == NULL) {
		root = new_node(data);
	} else if (data < root->data) {
		root->left = insert(root->left, data);
	} else {
		root->right = insert(root->right, data);
	}
	return root;
}

void preorder(node *root) {
	if (root != NULL) {
		printf("%d\n", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->data);
	}
}

void inorder(node *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d\n", root->data);
		inorder(root->right);
	}
}

int main() {
	node *root = NULL;
	int opt = 0;
	do {
		printf("1. insert node\n2. inorder traversal\n3. preorder traversal\n4. postorder traversal\n5. exit\n:: ");
		scanf("%d", &opt);
		switch(opt) {
			case 1:
				printf("enter value: ");
				int val;
				scanf("%d", &val);
				root = insert(root, val);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				printf("byee\n");
				break;
			default:
				printf("invalid option\n");
				break;
		}
	} while (opt != 5);
	return 0;
}
