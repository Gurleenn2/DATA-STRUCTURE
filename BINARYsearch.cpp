// code to implement array operation including insertion,deletion,binaryand linear search

#include <stdio.h>

#define SIZE 100

void insert(int arr[], int *n, int pos, int value);
void deleteElement(int arr[], int *n, int pos);
int linearSearch(int arr[], int n, int key);
int binarySearch(int arr[], int n, int key);

int main() {
    int arr[SIZE], i, choice, pos, value, key, result, size = 5;

    printf("Enter 5 values:\n");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements inserted: ");
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    while(1) {
        printf("\nMENU:\n");
        printf("1. Insertion\n2. Deletion\n3. Linear Search\n4. Binary Search\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &pos);
                if(pos < 0 || pos > size) {
                    printf("Invalid position.\n");
                    break;
                }
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(arr, &size, pos, value);
                printf("Array after insertion: ");
                for(i = 0; i < size; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 2:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &pos);
                if(pos < 0 || pos >= size) {
                    printf("Invalid position.\n");
                    break;
                }
                deleteElement(arr, &size, pos);
                printf("Array after deletion: ");
                for(i = 0; i < size; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 3:
                printf("Enter value to search (Linear): ");
                scanf("%d", &key);
                result = linearSearch(arr, size, key);
                if(result == -1)
                    printf("Element not found.\n");
                else
                    printf("Element found at index: %d\n", result);
                break;

            case 4:
                printf("Enter value to search (Binary - array must be sorted): ");
                scanf("%d", &key);
                result = binarySearch(arr, size, key);
                if(result == -1)
                    printf("Element not found.\n");
                else
                    printf("Element found at index: %d\n", result);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void insert(int arr[], int *n, int pos, int value) {
    if(*n >= SIZE) {
        printf("Array is full, cannot insert.\n");
        return;
    }
    for(int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

void deleteElement(int arr[], int *n, int pos) {
    for(int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}