#include <stdio.h>
#include <stdlib.h>
#define SPC 10
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

void display(node *root, int level) {
	if (root == NULL)
		return;
    level += SPC;
	display(root->right, level + 1);
    putchar('\n');
	for (int i = 0; i < level; i++) {
		putchar(' ');
    }
	printf("%d\n", root->data);
	display(root->left, level + 1);
}

int main() {
	node *root = NULL;
	int opt = 0;
	do {
		printf("1. add node\n2. display\n3. exit\n::");
		scanf("%d", &opt);
		switch(opt) {
			case 1:
				printf("enter value: ");
				int val;
				scanf("%d", &val);
				root = insert(root, val);
				break;
			case 2:
				display(root, 1);
				break;
			case 3:
				printf("byee\n");
				break;
			default:
				printf("invalid option\n");
				break;
		}
	} while(opt != 3);
}
