include header.mk
n=sync
$(n).$(TAREXT):$(n).c aoeiuv.h
	gcc -Wall -Wpedantic --save-temps -o $(n).$(TAREXT) $(n).c
	.$(PS)$(n).$(TAREXT)
.PHONY:clean
.IGNORE:clean
clean:
	$(RM) *.i *.o *.s *.$(TAREXT)


