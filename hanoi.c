#include <stdio.h>
int count = 0;
void move(int n, char from, char aux, char to) {
    if (n > 0) {
        move(n - 1, from, to, aux);
        printf("%d. moved %d th tower from %c to %c\n", ++count, n,  from, to);
        move(n - 1, aux, from, to);
    }
}

int main() {
    printf("Enter the number of disks: ");
    int n;
    scanf("%d", &n);
    move(n, 'A', 'B', 'C');
    printf("a total of %d moves\n", count);
    return 0;
}