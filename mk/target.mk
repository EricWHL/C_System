WARNING = -W -Wall -Wstrict-prototypes -Wmissing-prototypes
CC = gcc

CFLAGS  = -g -O2 $(WARNING) $(LCFLAGS)

SRCS = $(foreach dir, $(SUBDIRS), $(wildcard $(dir)/*.c))
CPLF = $(foreach dir, $(SUBDIRS), $(wildcard $(dir)/*.o))

OBJS = $(patsubst %.c, %.o, $(SRCS))

os.bin:$(OBJS)
	$(CC) $(OBJS) -o $@

%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf *.bin *.exe $(CPLF)
