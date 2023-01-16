create:
	gcc main.c filehash.c -W -Wall -o hash 

start:
	./hash testfile.txt qwerty123 hashfile.txt

clear:
	rm hashfile.txt && rm hash
