MAIN_PATH = src/*.c 
MAIN_BIN  = bin/main
INCLUDE   = -I inc/
FUNCTTON  = $(wildcard fun/*.c)
FUNC_OBJ  = $(patsubst %.c,%.o,$(FUNCTTON))
LIB_PATH  = lib/libfunc.a
LIBRARY   = -L lib/ -lfunc

%.o:%.c
	gcc $^ -c -o $@ $(INCLUDE)

$(LIB_PATH):$(FUNC_OBJ)
	ar rcs $@ $^
	gcc $(MAIN_PATH) -o $(MAIN_BIN) $(INCLUDE) $(LIBRARY)

clean:
	rm $(MAIN_BIN)
	rm $(LIB_PATH)
	rm $(FUNC_OBJ)
