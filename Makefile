CC = gcc
CFLAGS = -Wall -fPIC
LIBS = -L. -ladd   # 链接本地的libadd.so库

all: main_static main_dynamic

# 半动态链接: 编译时链接动态库，运行时仍然需要.so文件
main_static: main.o libadd.so
	$(CC) -o main_static main.o $(LIBS)

# 完全动态链接: 程序在运行时手动加载.so文件
main_dynamic: main_dynamic.o
	$(CC) -o main_dynamic main_dynamic.o -ldl

# 编译主程序
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

main_dynamic.o: main_dynamic.c
	$(CC) $(CFLAGS) -c main_dynamic.c

clean:
	rm -f *.o *.so main_static main_dynamic