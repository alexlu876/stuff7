all: foo.c
	make clean
	touch bar
	gcc foo.c
run: foo.c
	make clean
	touch bar
	gcc foo.c
	./a.out
clean: 
	touch bar
	rm bar
