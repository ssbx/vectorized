.PHONY: clean run

vectorized: main.c
	#gcc -O3 -ftree-vectorizer-verbose=2 main.c -o vectorized
	gcc -O3 -ftree-vectorizer-verbose=1 main.c -o vectorized

run: vectorized
	./vectorized

clean:
	rm -f vectorized
