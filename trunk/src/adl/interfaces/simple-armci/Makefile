CC      = mpixlc_r 
COPT    = -g -O3 -qstrict

INCLUDE = -I. -I/bgsys/drivers/ppcfloor/arch/include/
LIBS    = libarmci-bgp.a

LD      = $(CC)
CFLAGS  = $(COPT) $(INCLUDE)
LDFLAGS = $(COPT)

OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c))
HEADERS := $(wildcard *.h)

all: libarmci-bgp.a $(TESTS)

libarmci-bgp.a: $(OBJECTS)
	$(AR) $(ARFLAGS) libarmci-bgp.a $(OBJECTS)

%.x: %.o
	$(LD) $(LDFLAGS) $< $(LIBS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJECTS)

realclean: clean
	$(RM) $(RMFLAGS) $(TESTS) libarmci-bgp.a
