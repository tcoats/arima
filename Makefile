# vim: set noet:
CC = emcc
CXX = em++

# FILES =  libmvar/mvardie.c libmvar/mvarfit.c libmvar/mvarmat.c libmvar/mvarsim.c libmvar/mvartest.c
FILES = ctsa/src/*.c

EXPORTED_FUNCTIONS="['_calc_arima', '_calc_sarima', '_calc_acf', '_calc_pacf']"

CFLAGS = -O3 -Wall -fPIC --memory-init-file 0
EMCFLAGS = -s ALLOW_MEMORY_GROWTH=1 -s EXPORTED_FUNCTIONS=$(EXPORTED_FUNCTIONS) -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap']" -s WASM=0 -s MODULARIZE=0

build:
	${CC} ${CFLAGS} ${EMCFLAGS} ${FILES} src/api.c -o ctsa.js -s BINARYEN_ASYNC_COMPILATION=0;

