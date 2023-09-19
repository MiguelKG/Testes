#include <stdio.h>
#include <stdlib.h>

void merge( int *v, int start, int end ) {
    if ( start == end ) return;
    int medium = ( start + end ) / 2;

    merge( v, start, medium );
    merge( v, medium + 1, end );

    int x1 = start;
    int y1 = medium;
    int x2 = medium + 1; 
    int y2 = end;

    int i = x1;
    int i2 = x2;
    int c = i;
    int temp;
    
    while( i <= y1 || i2 <= y2 ) {
        if ( ( i <= y1 && v[ i ] < v[ i2 ] ) || i2 > y2 ) {
            temp = v[ c ];
            v[ c ] = v[ i ];
            v[ i ] = temp;
        } else {
            if ( i2 < y2 && v[ i2 ] > v[ i2 + 1 ] ) {
                temp = v[ c ];
                v[ c ] = v[ i2 + 1 ];
                v[ i2 + 1 ] = temp;
            } else {
                temp = v[ c ];
                v[ c ] = v[ i2 ];
                v[ i2 ] = temp;
            }
        }
        if ( c <= medium ) {
            i++;
        } else {
            i2++;
        }
        c++;
    }
}

void merge_sort( int *v, int size ) {
    merge( v, 0, size - 1 );
}

int main()
{
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    merge_sort( arr, arr_size );
  
    for (int i = 0; i < arr_size; i++ ) {
        printf("%d ", arr[ i ]);
    }
    printf("\n");

    return 0;
}