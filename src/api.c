#include <stdio.h>
#include <stdlib.h>
#include "api.h"
#include "../ctsa/header/ctsa.h"

double* arima (
  double* ts,
  int p, int d, int q,
  int lin, int lout,
  int method, int opt, _Bool verbose) {
  arima_object obj;

  /* Print input series
  for (int i = 0; i < lin; i++) { printf("%d : %f \n", i, ts[i]); }
  */

  double *phi, *theta;
  double *res, *amse;

  theta = (double*)malloc(sizeof(double) * q);
  phi = (double*)malloc(sizeof(double) * p);

  obj = arima_init(p, d, q, lin);

  arima_setMethod(obj, method);
  arima_setOptMethod(obj, opt);
  arima_exec(obj, ts);

  res = (double*)malloc(sizeof(double) * lout * 2);
  amse = res + lout;

  arima_predict(obj, ts, lout, res, amse);

  if (verbose) {
    arima_summary(obj);
  }

  free(phi);
  free(theta);

  return res;
}

double* sarima (
  double* ts,
  int p, int d, int q,
  int s, int P, int D, int Q,
  int lin, int lout, int method, int opt, _Bool verbose) {
  sarima_object obj;

  /* Print input series
  for (int i = 0; i < lin; i++) { printf("%d : %f \n", i, ts[i]); }
  */

  double *phi, *theta;
  double *res, *amse;

  theta = (double*)malloc(sizeof(double) * q);
  phi = (double*)malloc(sizeof(double) * p);

  obj = sarima_init(p, d, q, s, P, D, Q, lin);

  sarima_setMethod(obj, method);
  sarima_setOptMethod(obj, opt);
  sarima_exec(obj, ts);

  res = (double*)malloc(sizeof(double) * lout * 2);
  amse = res + lout;

  sarima_predict(obj, ts, lout, res, amse);

  if (verbose) {
    sarima_summary(obj);
  }

  free(phi);
  free(theta);

  return res;
}

