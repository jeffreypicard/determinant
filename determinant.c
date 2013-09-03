/*
 * determinant.c
 *
 * Main program for determinant.
 *
 * Author: Jeffrey Picard
 */
#include <stdio.h>
#include <stdlib.h>

#include "determinant.h"

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
