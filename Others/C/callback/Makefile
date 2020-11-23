CC = gcc
AR = ar
#CFLAGS = -O2 -W -Wall

LIB_TARGET = lib.a
LIB_SRC = lib.c
LIB_OBJ = lib.o
SRC = callback.c

all:$(LIB_TARGET) $(SRC)
	$(CC) $(SRC) $(LIB_TARGET) -o test

$(LIB_OBJ):$(LIB_SRC)
	$(CC)  -c $(LIB_SRC) -o $(LIB_OBJ)

$(LIB_TARGET):$(LIB_OBJ)
	$(AR) rcs -o $(LIB_TARGET)  $(LIB_OBJ) 

clean:
	rm *.o *.a

ifeq (1,0)
	https://blog.csdn.net/sinohenu/article/details/70598969
	gcc 顺序
endif
