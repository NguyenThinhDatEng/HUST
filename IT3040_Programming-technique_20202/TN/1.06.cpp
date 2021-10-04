void reversearray(int arr[], int size) {
    int l = 0, r = size - 1, tmp;
    while (l < r)
    {
        tmp = arr[r];
        arr[r] = arr[l];
        arr[l] = tmp;
        l++;
        r--;
    }
}

void ptr_reversearray(int* arr, int size) {
    int l = 0, r = size - 1, tmp;
    while (l < r)
    {
        tmp = *(arr + r);
        *(arr + r) = *(arr + l);
        *(arr + l) = tmp;
        l++;
        r--;
    }
}