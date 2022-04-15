#
# Build static and shared libraries for raspidmx
#

LIB=raspidmx
LIBPNG=raspidmxPng
LIBQOI=qoi

OBJS=../common/backgroundLayer.o ../common/imageGraphics.o ../common/key.o \
 ../common/font.o ../common/imageKey.o ../common/hsv2rgb.o \
 ../common/imageLayer.o ../common/image.o ../common/imagePalette.o

OBJSPNG=../common/spriteLayer.o ../common/loadpng.o ../common/savepng.o ../common/scrollingLayer.o
OBJSQOI=../common/loadqoi.o

CFLAGS+=-Wall -g -O3 -I../common $(shell libpng-config --cflags)
LDFLAGS+=-L/opt/vc/lib/ -lbcm_host -lm
LDFLAGSPNG=${LDFLAGS} $(shell libpng-config --ldflags)

INCLUDES+=-I/opt/vc/include/ -I/opt/vc/include/interface/vcos/pthreads -I/opt/vc/include/interface/vmcs_host/linux

all: $(LIB) $(LIBPNG) $(LIBQOI)

%.o: %.c
	@rm -f $@ 
	$(CC) $(CFLAGS) $(INCLUDES) -g -c $< -o $@ -Wno-deprecated-declarations

$(LIB): $(OBJS)
	$(AR) rcs lib$(LIB).a $(OBJS)

$(LIBPNG): $(OBJSPNG)
	$(AR) rcs lib$(LIBPNG).a $(OBJSPNG)

$(LIBQOI): $(OBJSQOI)
	$(AR) rcs lib$(LIBQOI).a $(OBJSQOI)


clean:
	@rm -f $(OBJS)
	@rm -f lib$(LIB).a
