include header.mk
n=ls
$(n).$(TAREXT):$(n).c
	gcc -Wall -Wpedantic -std=c99 --save-temps -o $(n).$(TAREXT) $(n).c -L/usr/local/lib 
	.$(PS)$(n).$(TAREXT)
.PHONY:clean
.IGNORE:clean
clean:
	$(RM) *.i *.o *.s *.$(TAREXT)


