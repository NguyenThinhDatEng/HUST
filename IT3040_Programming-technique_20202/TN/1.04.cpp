int counteven(int* arr, int size) {
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0) count++;
    }

    return count;
}