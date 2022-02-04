#include <stdio.h>

typedef struct {
    int emp_no;
    char name[20];
    int bas_sal;
    int da;
} emp_data;

int main() {
    printf("enter the number of employees: ");
    int n;
    scanf("%d", &n);
    emp_data arr[n];
    for (int i = 0; i < n; i++) {
        printf("employ data input number %d::\n", i+1);
        printf("enter employee number: ");
        scanf("%d", &arr[i].emp_no);
        printf("enter employee name: ");
        scanf("%s", arr[i].name);
        printf("enter basic sal: ");
        scanf("%d", &arr[i].bas_sal);
        printf("enter da: ");
        scanf("%d", &arr[i].da);
    }
    FILE *fil_ref = fopen("emp_report", "w");
    fprintf(fil_ref, "%5s  %6s  %20s  %7s  %-7s  %-10s\n", "sl.no", "emp_no", "emp_name", "bas_sal", "da", "total_sal");
    fprintf(fil_ref, "--------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        fprintf(fil_ref, "%-5d  %-6d  %20s  %-7d  %-7d  %-10d\n", i + 1, arr[i].emp_no, arr[i].name, arr[i].bas_sal, arr[i].da, arr[i].bas_sal + arr[i].da);
    }
    fprintf(fil_ref, "-------------END OF DATA----------------\n");
    return 0;
}
