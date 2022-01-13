build:
	gcc -g -Wall -std=c17 ./src/*.c -o2 -o pokersquare	

run:
	./pokersquare

clean:
	rm -rf pokersquare