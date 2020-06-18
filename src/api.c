#include <stdio.h>
#include <stdlib.h>
#include "api.h"
#include "../ctsa/header/ctsa.h"

double* calc_arima (
  double* ts,
  int p, int d, int q,
  int lin, int lout,
  int method, int opt, _Bool verbose) {
  arima_object obj;

  double *res, *amse;

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

  return res;
}

double* calc_sarima (
  double* ts,
  int p, int d, int q,
  int s, int P, int D, int Q,
  int lin, int lout, int method, int opt, _Bool verbose) {
  sarima_object obj;

  double *res, *amse;

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

  return res;
}

double* calc_acf (
  double* ts,
  int lin, int lout, int method) {
  double *res;

  res = (double*)malloc(sizeof(double) * lout);

  acvf_opt(ts, lin, method, res, lout);
  acvf2acf(res, lout);

  return res;
}

double* calc_pacf (
  double* ts,
  int lin, int lout, int method) {
  double *res;

  res = (double*)malloc(sizeof(double) * lout);

  pacf_opt(ts, lin, method, res, lout);

  return res;
}

