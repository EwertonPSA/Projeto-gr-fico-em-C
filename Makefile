#EWERTON PATRICK SILVA DO AMARA USP ICMC
all:
	gcc -o exe main.c create_picture.c readLine.c -lm -I.
run:
	@./exe
