#include <stdio.h>
#include <stdlib.h>

void quick_sort( int *v, int left, int right, int* count );
void Quicksort ( int data[], int left, int right, int* count );

int main () {
    int v[ 8 ] = { 5, 6, 7, 8, 1, 2, 3, 4 };
    int count = 0;
    const int SIZE = sizeof( v ) / sizeof( int );
    quick_sort( v, 0, SIZE - 1, &count );

    for ( int i = 0; i < SIZE; i++ ) {
        printf( "%d ", v[ i ] );
    }
    printf( "\nCycles = %d", count );
}

void quick_sort( int *v, int left, int right, int *count ) {
    ( *count )++;
    if ( left > right || right < left ) return;

    int temp;
    int min = left;
    int pivot = right;

    int i;
    for ( i = left; i < right; i++ ) {
        if ( v[ i ] <= v[ pivot ] ) {
            temp = v[ min ];
            v[ min ] = v[ i ];
            v[ i ] = temp;
            min++;
        }
    }
    temp = v[ min ];
    v[ min ] = v[ pivot ];
    v[ pivot ] = temp;

    if ( left < min - 1 ) {
        quick_sort( v, left, min - 1, count );
    }
    if ( min + 1 < right ) {
        quick_sort( v, min + 1, right, count );
    }
}