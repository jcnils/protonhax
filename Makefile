.PHONY: all build clean

all: build

clean:
	rm envsave envload

build: envsave envload

%: %.c
	tcc -o $@ $<
