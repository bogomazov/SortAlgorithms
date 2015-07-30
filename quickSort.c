#include <stdio.h>

int getLength(FILE *in) {
    int length = 0;
    
    fscanf(in, "%d", &length);
    return length;
}

int partition(int array[], int start, int end) {
    int avarage = (start + end) / 2;
    int pivot = array[avarage];
    int tail;
    
    array[avarage] = array[end];
    array[end] = pivot;
    
    for ( tail = start; array[tail] < array[end]; tail++ );
    for ( int i = tail + 1; i < end; i++ ) {
        if ( array[i] <= array[end] ) {
            int tmp = array[i];
            
            array[i] = array[tail];
            array[tail] = tmp;
            tail += 1;
        }
    }
    pivot = array[tail];
    array[tail] = array[end];
    array[end] = pivot;
    
    return tail;
}

void quickSort(int array[], int lo, int hi) {
    int pivot;
    
    if ( hi - lo < 1 ) {
        return;
    }
    pivot = partition(array, lo, hi);
    
    quickSort(array, lo, pivot-1);
    quickSort(array, pivot+1, hi);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = getLength(in);
    int array[len-1];
    
    for ( int i = 0; i < len && fscanf(in, "%d", &array[i]) != 0; i += 1 );
    
    quickSort(array, 0, len-1);
    
    for ( int i = 0; i < len - 1; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[len-1]);
    
    fclose(in);
    fclose(out);
    
    return 0;
}
