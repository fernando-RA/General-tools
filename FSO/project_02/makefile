system: clean main.o 
	gcc main.c -lm -o prog
	rm -rf *.o
	./prog
main.o: main.c
	gcc -c main.c -o main.o -lm
clean:
	rm -rf *.o
