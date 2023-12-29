CC=gcc
CFLAGS=-Wall -I include
OBJS=main.o word.o letterpos.o
EXEC=shortwords

%.o: %.c ./include/word.h
	$(CC) -c -o $@ $< $(CFLAGS)

shortwords: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
ifeq ($(OS),Windows_NT)
	del $(OBJS)
else
	rm $(OBJS)
endif

clean:
ifeq ($(OS),Windows_NT)
	del $(EXEC).exe
else
	rm $(EXEC)
endif