//Move all zeroes to end of array
#include <stdio.h>

void moveZeroesToEnd(int arr[], int size) {
    int count = 0; 
    
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }
    
    while (count < size) {
        arr[count++] = 0;
    }
}

int main() {
    int size, arr[100];
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    moveZeroesToEnd(arr, size);
    
    printf("Array after moving zeroes to the end: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
