#include <stdio.h>

int getLength(FILE *in) {
    int length = 0;
    
    fscanf(in, "%d", &length);
    return length;
}

void merge(int numbers[], int temp[], int left, int mid, int right) {
    int left_end, num_elements, tmp_pos;
    
    left_end = mid - 1;
    tmp_pos = left;
    num_elements = right - left + 1;
    
    for ( ; left <= left_end && mid <= right; ) {
        if ( numbers[left] <= numbers[mid] ) {
            temp[tmp_pos] = numbers[left];
            tmp_pos = tmp_pos + 1;
            left = left + 1;
        } else {
            temp[tmp_pos] = numbers[mid];
            tmp_pos = tmp_pos + 1;
            mid = mid + 1;
        }
    }
    
    for ( ; left <= left_end; ) {
        temp[tmp_pos] = numbers[left];
        left = left + 1;
        tmp_pos = tmp_pos + 1;
    }
    for ( ; mid <= right; ) {
        temp[tmp_pos] = numbers[mid];
        mid = mid + 1;
        tmp_pos = tmp_pos + 1;
    }
    for ( int i = 0; i <= num_elements; i++ ) {
        numbers[right] = temp[right];
        right = right - 1;
    }
}

void m_sort(int numbers[], int temp[], int left, int right) {
    int mid;
    
    if ( right > left ) {
        mid = (right + left) / 2;
        m_sort(numbers, temp, left, mid);
        m_sort(numbers, temp, mid+1, right);
        merge(numbers, temp, left, mid+1, right);
    }
}

void mergeSort(int numbers[], int temp[], int array_size) {
    m_sort(numbers, temp, 0, array_size-1);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = getLength(in);
    int array[len-1];
    int temp[len-1];
    
    for ( int i = 0; i < len && fscanf(in, "%d", &array[i]) != 0; i += 1 );
    
    mergeSort(array, temp, len);
    
    for ( int i = 0; i < len - 1; i++ ) {
        fprintf(out, "%d ", temp[i]);
    }
    fprintf(out, "%d\n", temp[len-1]);
    
    fclose(in);
    fclose(out);
    
    return 0;
}
