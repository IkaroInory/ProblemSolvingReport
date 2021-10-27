CC=gcc
CFLAGS= -g -Wall
OBJS= ComputeTask.o IOTask.o mainProg.o
TARGET=mainProg

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(TARGET) $(OBJS)
