#!/bin/bash

cd /source/arima
apt-get update
apt-get install -y git python make libomp-dev
cd ../
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
. ./emsdk_env.sh
cd ../arima
npm i
CPATH=/usr/lib/llvm-10/include/openmp make
echo 'Run "CPATH=/usr/lib/llvm-10/include/openmp npm run build" to rebuild.'
echo 'All finished!'
exec bash