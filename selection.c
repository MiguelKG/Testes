#include <stdio.h>
#include <stdlib.h>

void selection_sort ( int v[], int size );

int main () {
    int v[10] = { 15, 32, 44, 1, 56, 24, 18, 13, 99, 13 };
    selection_sort( v, sizeof( v ) / sizeof( int ) );

    for ( int i = 0; i < sizeof( v ) / sizeof( int ); i++ ) {
        printf("%d ", v[ i ]);
    }
}


int min;
void selection_sort ( int v[], int size ) {
    int temp = -1;
    for ( int i = 0; i < size - 1; i++ ) {
        min = i;
        for ( int i2 = i; i2 < size; i2++ ) {
            if ( v[ i2 ] < v[ min ] ) {
                min = i2;
            }
        }
        temp = v[ i ];
        v[ i ] = v[ min ];
        v[ min ] = temp;
    }
}