include header.mk
n=setsid
$(n).$(TAREXT):$(n).c aoeiuv.h
	gcc -Wall -Wpedantic --std=gnu11 --save-temps -o $(n).$(TAREXT) $(n).c
	.$(PS)$(n).$(TAREXT)
.PHONY:clean
.IGNORE:clean
clean:
	$(RM) *.i *.o *.s *.$(TAREXT) *.d


