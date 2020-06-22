# ctsa

**Univariate ARIMA (Autoregressive Integrated Moving Average)**

Emscripten port of the native C package [ctsa](https://github.com/rafat/ctsa) for univariate time series analysis and prediction.

### API
Interface of `ctsa` consists of four functions that all take a 1D vector with observations over time.

```javascript
const ctsa = require('ctsa')
const diff = ctsa.diff(ts, 1, 1) // lag, differences
const acf = ctsa.acf(ts, 20, {
  method: 0 // ACF method Default
})
const pacf = ctsa.pacf(ts, 20, {
  method: 0 // PACF method Yule-Walker Default
})
const [pred, errors] = ctsa.arima(ts, 20, {
  method: 0, // ARIMA method (Default: 0)
  optimizer: 6, // Optimization method (Default: 6)
  p: 1, // Number of Autoregressive coefficients
  d: 0, // Number of times the series needs to be differenced
  q: 1, // Number of Moving Average Coefficients
  verbose: true // Output model analysis to console
})
const [pred, errors] = ctsa.sarima(ts, 20, {
  method: 0, // ARIMA method (Default: 0)
  optimizer: 6, // Optimization method (Default: 6)
  p: 1, // Number of Autoregressive coefficients
  d: 0, // Number of times the series needs to be differenced
  q: 1, // Number of Moving Average Coefficients
  s: 12, // Seasonal lag
  P: 0, // Number of seasonal Autoregressive coefficients
  D: 1, // Number of seasonal times the series needs to be differenced
  Q: 1, // Number of seasonal Moving Average Coefficients
  verbose: true // Output model analysis to console
})
```

### ARIMA Method (method)
```
0 - Exact Maximum Likelihood Method (Default)
1 - Conditional Method - Sum Of Squares
2 - Box-Jenkins Method
```

### Optimization Method (optimizer)
```
0 - Nelder-Mead
1 - Newton Line Search
2 - Newton Trust Region - Hook Step
3 - Newton Trust Region - Double Dog-Leg
4 - Conjugate Gradient
5 - BFGS
6 - Limited Memory BFGS (Default)
7 - BFGS Using More Thuente Method
```

### ACF Method
```
0 - Default Method
1 - FFT Based method
```

### PACF Method
```
0 - Yule-Walker
1 - Burg
2 - Conditional MLE (Box-Jenkins)
```

### Web demo
You can try ARIMA online in the Forecast app:  [https://statsim.com/forecast/](https://statsim.com/forecast/).
It uses the original [`arima`](https://github.com/zemlyansky/arima) package under the hood and applies random search method to find the best values of `p`, `d` and `q`.
