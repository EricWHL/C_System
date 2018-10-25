WARNING = -W -Wall -Wstrict-prototypes -Wmissing-prototypes
CC = gcc

CFLAGS  = -g -O2 $(WARNING) $(LCFLAGS)

SRCS = $(foreach dir, $(SUBDIRS), $(wildcard $(dir)/*.c))
CPLF = $(foreach dir, $(SUBDIRS), $(wildcard $(dir)/*.o))

OBJS = $(patsubst %.c, %.o, $(SRCS))

os:$(OBJS)
	$(CC) -g $(OBJS) -o $@ $(CFLAGS)

%.o:%.c
	$(CC) -c -g $< -o $@ $(CFLAGS)

clean:
	rm -rf os *.bin *.exe $(CPLF)
