GCC = gcc
ifdef CROSS-COMPILE
  COMPILER = $(CROSS-COMPILE)$(GCC)
else
  COMPILER = $(GCC)
endif

writer: writer.c
		$(COMPILER) writer.c -o writer

clean: 
		rm -f *.o writer
