CC= gcc
AR= ar
CPPFLAGS=
CFLAGS= -Wall -std=c99
LDFLAGS= -L.
EXEC=game_text
all:$(EXEC)

game_aux.o:game_aux.c game_aux.h
	$(CC) $(CFLAGS) -c  $<

libgame.a:game.o game_aux.o
	$(AR) rcs $@ $^

game_text:game_text.c libgame.a
	$(CC) $(CFLAGS) $^ -o $@

clean :
	-rm -f game_aux.o *.a $(EXEC)


