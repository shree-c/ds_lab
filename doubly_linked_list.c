#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
    struct node *before;
} node;

node *newNode(int data, node *next, node *before) {
    node *hold = (node *) malloc(sizeof(node));
    hold->data = data;
    hold->next = next;
    hold->before = before;
    return hold;
}

void printLlist(node *start) {
    if (start == NULL) {
        printf("list empty\n");
        return;
    }
    node *hold = start;
    while (hold != NULL) {
        printf("--> %d\n", hold->data);
        hold = hold->next;
    }
}
node *add_back(node *start, int val) {
    if (start == NULL) {
        start = newNode(val, NULL, NULL);
    } else {
        node *hold = start;
        while (hold->next != NULL)
            hold = hold->next;
        hold->next = newNode(val, NULL, hold);
    }
    return start;
}

node *add_front(node *start, int val) {
    if (start == NULL) {
        start = newNode(val, NULL, NULL);
    } else {
        start = newNode(val, start, NULL);
    }
    return start;
}
node *remove_front(node *start) {
    if (start == NULL) {
        printf("list empty\n");
    } else {
        if (start->next == NULL) {
            printf("%d removed\n", start->data);
            free(start);
            start = NULL;
        } else {
            node *hold = start;
            printf("%d removed\n", hold->data);
            start = start->next;
            start->before = NULL;
            free(hold);
        }
    }
    return start;
}
node *remove_back(node *start) {
    if (start == NULL) {
        printf("list empty\n");
    } else {
        node *hold = start;
        if (hold->next == NULL) {
            printf("%d removed\n", hold->data);
            start = NULL;
            free(hold);
        } else {
            while (hold->next->next != NULL)
                hold = hold->next;
            printf("%d removed\n", hold->next->data);
            free(hold->next);
            hold->next = NULL;
        }
    }
    return start;
}

int main() {
	int opt = 0;
    node *start = NULL;
	do {
		printf("1. add_front\n2. add_back\n3. remove_front\n4. remove_back\n5. display\n6. exit\n:: ");
		scanf("%d", &opt);
		switch(opt) {
			case 1: {
				printf("Enter a value: ");
				int val;
				scanf("%d", &val);
                start = add_front(start, val);
				break;
            }
			case 2: {
				int val;
				scanf("%d", &val);
                start = add_back(start, val);
				break;
            }
			case 3:
                start = remove_front(start);
				break;
			case 4:
                start = remove_back(start);
				break;
            case 5:
				printLlist(start);
				break;
            case 6:
                printf("byee\n");
                break;
            default:
                printf("invalid option\n");
                break;
		}
	} while (opt != 6);
	return 0;
}
