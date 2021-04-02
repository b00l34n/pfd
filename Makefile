
.PHONY: build clean releas
.SUFFIXES: .c .hex .bin
.SECONDARY:

SOURCE         = main.c
LIB            = $(wildcard ./lib/*/*.c)
BIN            = main
C              = gcc
C_FLAG         = -Werror -Wall -fanalyzer -lm -o
C_FLAG_RELEASE = -O3 -fgraphite -flto -static -march=native -lm -o

default: build

build:
	$(C) $(C_FLAG) $(BIN) $(SOURCE) $(LIB) 

releas:
	$(C) $(C_FLAG_RELEASE) $(BIN) $(SOURCE) $(LIB) 

clean:
	@test -e $(BIN) && rm -r $(BIN)