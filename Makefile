CFLAGS := $(CFLAGS) -Wall -Werror -pedantic -march=native -O2 \
	$(shell sdl-config --cflags)
LDFLAGS := $(LDFLAGS) $(shell sdl-config --libs)
BIN_NAME = CRay

main:
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BIN_NAME) app.c

clean:
	rm -f $(BIN_NAME)
