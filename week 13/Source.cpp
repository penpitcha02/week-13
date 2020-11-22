#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);

int main() 
{
    int a, b, c, d, e, choice;
    printf("Enter numbers: ");
    scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);

    int arr[5] = { a, b, c, d, e };
    int num, width, i;
    num = sizeof(arr) / sizeof(arr[0]);
    width = sizeof(arr[0]);
    qsort((void*)arr, num, width, compare);

    do
    {
        printf("Enter Choice: 0 for min to max, 1 for max to min\n");
        while (getchar() != '\n');
        scanf_s("%d", &choice);
    } while (!(choice == 0 || choice == 1));


    if (choice == 0)
    {
        for (i = 0; i < 5; i++)
            printf("%d ", arr[i]);
    }
    if (choice == 1)
    {
        for (i = 4; i >= 0; i--)
            printf("%d ", arr[i]);
    }
    return 0;
}

int compare(const void* elem1, const void* elem2)
{
    if ((*(int*)elem1) == (*(int*)elem2))  return 0;
    else if ((*(int*)elem1) < (*(int*)elem2)) return -1;
    else return 1;
}