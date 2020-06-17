const ctsa = require('./ctsa.js')

const _arima = ctsa.cwrap('arima', 'number', [
  'array',
  'number', 'number', 'number',
  'number', 'number', 'number', 'number', 'boolean'])
const _sarima = ctsa.cwrap('sarima', 'number', [
  'array',
  'number', 'number', 'number',
  'number', 'number', 'number', 'number',
  'number', 'number', 'number', 'number', 'boolean'])

const writedoublearray = arr => {
  const farr = arr.flat()
  for (let i = 0; i < farr.length - 2; i++)
    if (isNaN(farr[i + 1]))
      farr[i + 1] = farr[i]
  return new Uint8Array(Float64Array.from(farr).buffer)
}

const readdoublearray = (addr, length) => {
  const res = [[], []]
  for (let i = 0; i < length * 2; i++)
    res[i < length ? 0 : 1].push(ctsa.HEAPF64[addr / Float64Array.BYTES_PER_ELEMENT + i])
  return res
}

const arima_defaults = {
  method: 0,
  optimizer: 6,
  p: 1,
  d: 0,
  q: 1,
  verbose: true
}

const sarima_defaults = {
  method: 0,
  optimizer: 7,
  p: 0,
  d: 1,
  q: 1,
  s: 12,
  P: 0,
  D: 1,
  Q: 1,
  verbose: true
}

module.exports = {
  predict(input, length, opts) {
    const options = Object.assign({}, arima_defaults, opts)
    const ts = writedoublearray(input)
    const addr = _arima(
      ts,
      options.p,
      options.d,
      options.q,
      input.length,
      length,
      options.method,
      options.optimizer,
      options.verbose
    )
    return readdoublearray(addr, length)
  },
  spredict(input, length, opts) {
    const options = Object.assign({}, sarima_defaults, opts)
    const ts = writedoublearray(input)
    const addr = _sarima(
      ts,
      options.p,
      options.d,
      options.q,
      options.s,
      options.P,
      options.D,
      options.Q,
      input.length,
      length,
      options.method,
      options.optimizer,
      options.verbose
    )
    return readdoublearray(addr, length)
  }
}
