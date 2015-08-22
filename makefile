include header.mk
n=dup
$(n).$(TAREXT):$(n).c aoeiuv.h
	gcc -Wall -Wpedantic -std=c99 --save-temps -o $(n).$(TAREXT) $(n).c
	#.$(PS)$(n).$(TAREXT)
.PHONY:clean
.IGNORE:clean
clean:
	$(RM) *.i *.o *.s *.$(TAREXT)


