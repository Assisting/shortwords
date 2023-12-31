CC=gcc
CFLAGS=-Wall -Wpedantic -Wextra -I include
OBJS=main.o word.o letterpos.o
EXEC=shortwords

%.o: %.c ./include/word.h
	$(CC) -c -o $@ $< $(CFLAGS)

shortwords: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	rm $(OBJS)

clean:
	rm $(EXEC)