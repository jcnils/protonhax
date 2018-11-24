.PHONY: all build clean

all: build

clean:
	rm envload

build: envload

%: %.c
	tcc -o $@ $<
