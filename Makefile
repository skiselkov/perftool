OBJS = perf.o

ACFUTILS=../libacfutils
CFLAGS = -W -Wall -Werror -g -I$(ACFUTILS)/src \
    $(shell $(ACFUTILS)/pkg-config-deps linux-64 --cflags)
LIBS = -L$(ACFUTILS)/qmake/lin64 -lacfutils \
    $(shell $(ACFUTILS)/pkg-config-deps linux-64 --libs) \
    -lm

all : perf

clean :
	rm -f $(OBJS) perf

perf : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

%.o : %c
	$(CC) -c -o $@ $(CFLAGS) $^
