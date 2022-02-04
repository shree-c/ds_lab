#include <stdio.h>

struct item {
	char item_name[20];
	int qty;
	int price;
};

int main() {
	printf("Enter the number of items: ");
	int n;
	scanf("%d", &n);
	printf("Enter the number of friends: ");
	int m;
	scanf("%d", &m);
	struct item arr[n];
	printf("Enter %d item details: \n", n);
	int total = 0;
	for (int i = 0; i < n; i++) {
		printf("item name: ");
		scanf("%s", arr[i].item_name);
		printf("item price: ");
		scanf("%d", &arr[i].price);
		printf("item quantity: ");
		scanf("%d", &arr[i].qty);
		total += arr[i].qty * arr[i].price;
	}
	printf("Each friend has to pay: %.2f amount of money.\n", (float)total/m);
	return 0;
}
	
