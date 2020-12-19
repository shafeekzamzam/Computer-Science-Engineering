/******************************************

  Application: Matrix Multiplication
  Compiled on: Borland Turbo C++ 3.0
  Programmer : Geetika Mukhi

******************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

void
  RecordData( int mt[ ][ MAXSIZE ], int n ),
  Multiply( int mt1[ ][ MAXSIZE ], int mt2[ ][ MAXSIZE ],
        int mt3[ ][ MAXSIZE ], int size ),
  ShowResult( int mt[ ][ MAXSIZE ], int size );

void main()
{
  int size;
  int mt1[ MAXSIZE ][ MAXSIZE ],
      mt2[ MAXSIZE ][ MAXSIZE ],
      mt3[ MAXSIZE ][ MAXSIZE ];
  char checkAnotherOperation;

  checkAnotherOperation='y';

  while(checkAnotherOperation=='y')
  {
    clrscr();
    /* Reads data of Matrix mt1 and mt2 and multiply the two matrices*/
    printf( "MATRIX MULTIPLICATION\n\n" );
    printf( "Please Enter the Matrix Size: " );
    scanf( "%d", &size );
    printf( "\nEnter the First Matrix:\n" );
    RecordData( mt1, size );
    printf( "\nMatrix mt1:\n" );
    ShowResult( mt1, size );
    printf( "\nEnter the Second Matrix:\n" );
    RecordData( mt2, size );
    printf( "\nMatrix mt2:\n" );
    ShowResult( mt2, size );

    Multiply( mt1, mt2, mt3, size );

    /* Show the resultant matrix */
    printf( "\nResultant Matrix mt3 After Multiplication of mt1 and mt2:\n" );
    ShowResult( mt3, size );
    printf("\nWould like to perform another matrix multiplication? (y/n):");
    fflush(stdin);
    checkAnotherOperation=getche();
  }

}

/* This function multiplies the two matrices and stores the result in a third matrix*/
void Multiply( int mt1[ ][ MAXSIZE ],
           int mt2[ ][ MAXSIZE ],
           int mt3[ ][ MAXSIZE ],
           int size )
{
  int l, m, n;

  for ( l = 0; l < size; l++ )
    for ( m = 0; m < size; m++ ) {
      mt3[ l ][ m ] = 0;
      for ( n = 0; n < size; n++ )
        mt3[ l ][ m ] += mt1[ l ][ m ] * mt2[ n ][ m ];
    }
}

/* This function records the data of a matrix*/
void RecordData( int mt[ ][ MAXSIZE ], int size )
{
  int row, col;

  for ( row = 0; row < size; row++ )
    for ( col = 0; col < size; col++ )
      scanf( "%d", &mt[ row ][ col ] );
}

/* This function prints the contents of a matrix*/
void ShowResult( int mt[ ][ MAXSIZE ], int size )
{
  int row, col;

  for ( row = 0; row < size; row++ ) {
    for ( col = 0; col < size; col++ )
      printf( "%d ", mt[ row ][ col ] );
    putchar( '\n' );
  }
}
