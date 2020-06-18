#ifndef API_H_
#define API_H_

#ifdef __cplusplus
extern "C" {
#endif

double* calc_arima (
  double* ts,
  int p, int d, int q,
  int lin, int lout, int method, int opt, _Bool verbose);

double* calc_sarima (
  double* ts,
  int p, int d, int q,
  int s, int P, int D, int Q,
  int lin, int lout, int method, int opt, _Bool verbose);

double* calc_acf (
  double* ts,
  int lin, int lout, int method);

double* calc_pacf (
  double* ts,
  int lin, int lout, int method);

#ifdef __cplusplus
}
#endif

#endif
