#include <stdio.h>

void insertion_sort( int v[], int size );

int main () {
    int v[] = { 1, 3, 4, 2, 7, 9, 22, 10, 12, 11, 16 };
    int size = sizeof( v ) / sizeof( int );
    insertion_sort( v, size );

    for ( int i = 0; i < size; i++ ) {
        printf( "%d ", v[ i ] );
    }
}

void insertion_sort( int v[], int size ) {
    int j, k, temp;
    for ( int i = 0; i < size; i++ ) {
        j = i;
        k = i - 1;
        while ( k >= 0 && v[ j ] < v[ k ] ) {
            temp = v[ j ];
            v[ j ] = v[ k ];
            v[ k ] = temp;
            j--;
            k--;
        }
    }
}