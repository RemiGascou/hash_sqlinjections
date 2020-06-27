.PHONY: all compile configure

CC := gcc
CFLAGS := -lpthread -lcrypto -D_GNU_SOURCE

DIR_SRC := ./src/
DIR_BIN := ./bin/

all : configure compile

configure :
	$(eval NCORES := $(shell lscpu | grep "^CPU(s):" | awk '{split($$0,a," "); print a[2]}'))
	@echo "[CONFIGURE] Detected ${NCORES} CPU. Compiling for ${NCORES} threads."
	@echo "[CONFIGURE] Detected openssl version : $(shell openssl version)"
	@sed -i "s/^#define _NUM_THREADS.*/#define _NUM_THREADS ${NCORES}/g" "$(DIR_SRC)/main.c"
	@if [ ! -d $(DIR_BIN) ]; then mkdir -p $(DIR_BIN); fi

compile : configure
	$(CC) $(DIR_SRC)main.c $(CFLAGS) -o $(DIR_BIN)hashsqli
