int main() {
    int a[] = {2, 3, 1, 2, 3};
    int size = sizeof(a) / sizeof(a[0]);
    int b[size];

    for (int i = 0; i < size; i++) {
        b[a[i]]++;
    }

    printf("Numbers occurring more than once:\n");
    for (int i = 0; i < size; i++) {
        if (b[i] > 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}