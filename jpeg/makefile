include ../header.mk
n=jpegview
$(n).$(TAREXT):$(n).c
	gcc -Wall -std=c99 --save-temps -o $(n).$(TAREXT) $(n).c -L/usr/local/lib -ljpeg
	.$(PS)$(n).$(TAREXT)
.PHONY:clean
.IGNORE:clean
clean:
	$(RM) *.i *.o *.s *.$(TAREXT)


