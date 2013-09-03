/*
 * determinant.h
 *
 * structs for determinant.c
 *
 * Author: Jeffrey Picard
 */
#ifndef DETERMINANT_H
#define DETERMINANT_H

#include <stdio.h>

struct {
  unsigned int  n;
  double        **data;
} typedef matrix_t;

enum {
  INTERACTIVE,
  FILE_NAME
} typedef input_loc;

struct {
  input_loc loc;
  FILE      *fp;
} typedef input_t;

#endif /* DETERMINANT_H */
