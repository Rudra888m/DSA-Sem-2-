#include<stdio.h>

void print_array(int arr[], int n) {
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int linear_search(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binary_search(int arr[], int n, int key) {
    int low = 0, high = n-1, mid;
    while(low <= high) {
        mid = (low+high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void bubble_sort(int arr[], int n) {
    int is_sorted = 0;
    for(int i = 0; i < n-1; i++) {
        is_sorted = 1;
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                is_sorted = 0;
            }
        }
        if(is_sorted)
            return;
    }
}

void insertion_sort(int arr[], int n) {
    int key, j;
    for(int i=1; i<n; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selection_sort(int arr[], int n) {
    int indexofMin, temp;
    for(int i=0; i<n-1; i++) {
        indexofMin = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[indexofMin])
                indexofMin = j;
        }
        temp = arr[i];
        arr[i] = arr[indexofMin];
        arr[indexofMin] = temp;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do {
        while(i <= high && arr[i] <= pivot)
            i++;
        while(j >= low && arr[j] > pivot)
            j--;
        if(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quick_sort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

void merge(int arr[], int low, int mid, int high) {
     int i = low;
     int j = mid + 1;
     int k = 0;
     int temp[high - low + 1];

     while(i <= mid && j <= high) {
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            k++;i++;
        }
        else {
            temp[k] = arr[j];
            k++;j++;
        }
     }

     while(i <= mid) {
        temp[k] = arr[i];
        k++;i++;
     }
     while(j <= high) {
        temp[k] = arr[j];
        k++;j++;
     }
     for(int i = low, j = 0; i <= high; i++,j++)
        arr[i] = temp[j];
}

void merge_sort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[100], n, choice, key, result;

    printf("\nEnter number of elements : ");
    scanf("%d", &n);

    printf("Enter elements : ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n---Sorting and searching Menu---\n");
        printf("1. Linear search\n");
        printf("2. Binary search\n");
        printf("3. Bubble sort\n");
        printf("4. Selection sort\n");
        printf("5. Insertion sort\n");
        printf("6. Quick sort\n");
        printf("7. Merge sort\n");
        printf("8. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key : ");
                scanf("%d", &key);
                result = linear_search(arr, n ,key);
                printf(result != -1 ? "Found at index %d\n" : "Not found\n", result);
                break;
            case 2:
                printf("Enter key : ");
                scanf("%d", &key);
                printf("Sorting array before binary search...\n");
                quick_sort(arr, 0, n-1);
                print_array(arr, n);
                result = binary_search(arr, n ,key);
                printf(result != -1 ? "Found at index %d\n" : "Not found\n", result);
                break;
            case 3:
                bubble_sort(arr, n);
                print_array(arr, n);
                break;
            case 4:
                selection_sort(arr, n);
                print_array(arr, n);
                break;
            case 5:
                insertion_sort(arr, n);
                print_array(arr, n);
                break;
            case 6:
                quick_sort(arr, 0, n-1);
                print_array(arr, n);
                break;
            case 7:
                merge_sort(arr, 0, n-1);
                print_array(arr, n);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. try again.\n");
                break;
        }
    } while(choice != 8);

    return 0;
}