CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = -lm
SRCS = src/parser.c src/cfg_builder.c src/static_analyzer.c src/reporter.c src/main.c
OBJS = $(SRCS:.c=.o)
EXEC = static-analysis-dead-code-memory-leak-detector

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(EXEC)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	$(EXEC) --check-memory-leaks --check-dead-code

test: all
	./tests/test_runner

clean:
	rm -f $(OBJS) $(EXEC)