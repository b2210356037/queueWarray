#include <stdio.h>
#include <stdlib.h>

int* array = NULL; // Neden null ?
int first = 0, last = 0, size = 2;

int dequeue() { // Eleman çıkarma
    if (last == first) {
        printf("Queue is empty");
        return -1;
    }

    if (last - first <= size / 4) {
        int* array2 = (int*)malloc(sizeof(int) * size / 2);

        int i = 0;
        for (i = 0; i < last - first; i++) {
            array2[i] = array[first + i];
        }
        last -= first;
        first = 0;
        free(array);
        size /= 2;
        array = array2;

    }
    return array[first++];
}

void clear() {
    if (first == 0)
        return;
    int i = 0;
    for (i = 0; i < size; i++) {
        array[i] = array[i + first];
    }
    last -= first;
    first = 0;
}
int enqueue(int a) {
    if (array == NULL) {
        array = (int*)malloc(sizeof(int) * 2);
    }

    if (last >= size) {
        size *= 2;
        int* array2 = (int*)malloc(sizeof(int) * size);
        int i = 0;
        for (i = 0; i < size / 2; i++)
            array2[i] = array[i];

        free(array);
        array = array2;
    }
    return  array[last++] = a;
}

int main() {
    int i = 0;
    int sayac = 0;
    for (i = 0; i < 20; i++) {
        printf("%d ", enqueue(i * 10));

    }
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%d ", dequeue());
    }


}