src = $(wildcard src/*.c)
inc = -I inc/
fun = $(wildcard fun/*C)
obj = $(patsubst %.c,%.o,$(fun))
lib = lib/libfun.a

%.o:%.c
	gcc $^ -c -o %@ $(inc)
$(lib):$(obj)
	ar rcs $@ $^
clean:
	rm bin/test

