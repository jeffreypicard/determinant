/*
 * determinant.c
 *
 * Main program for determinant.
 *
 * Author: Jeffrey Picard
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "determinant.h"

double **
matrix_minor( double **m, unsigned int n, unsigned int skip_row, 
              unsigned int skip_col )
{
  unsigned int i = 0, j = 0;
  double **minor = malloc( (n-1) * (n-1) * sizeof **minor );
  if (!minor) {
    fprintf( stderr, "Error: malloc failed in matrix_minor\n");
    exit(-1);
  }

  for ( unsigned int row = 0; row < n; row++ ) {
    if ( row == skip_row )
      continue;
    for ( unsigned int col = 0; col < n; col++ ) {
      if ( col == skip_col )
        continue;
      minor[i][j] = m[row][col];
      j++;
    }
    i++;
  }
  return minor; 
}

double
do_determinant( double **m, unsigned int n, unsigned int row )
{
  if ( n == 1 )
    return **m;
  if ( n == 2 )
    return m[0][0] * m[1][1] - m[1][0] * m[0][1];
  double det = 0;
  for ( unsigned int col = 0; col < n; col++ ) {
    double **minor = matrix_minor( m, n, row, col );
    det += pow( -1, row + col ) * do_determinant( minor, n-1, row );
    free( minor );
  }
  return det;
}

double
determinant( matrix_t *m )
{
  return do_determinant( m->data, m->n, 1 );  
}

int
read_matrix( matrix_t **m, input_t *input_info )
{
  return 0;
}

int
main( int argc, char **argv )
{
  matrix_t *m;
  input_t input_info;

  input_info.loc = INTERACTIVE;
  input_info.fp = NULL;

  if ( read_matrix( &m, &input_info ) != 0 )
    return EXIT_FAILURE;
    
  return EXIT_SUCCESS;
}
