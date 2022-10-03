#include <stdio.h>
#include <unistd.h>

void reverse_print(const int arr[], size_t size) {
    for (size_t index = size; index >= 0; --index) {
        printf("%d ", arr[index]);
        /* // Uncomment to test attach to running process
        printf("\n");
        sleep(1);
        */
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};

    size_t n_elems = sizeof(arr) / sizeof(arr[0]);

    reverse_print(arr, n_elems);

    return 0;
}
