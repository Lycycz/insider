# Makefile for ARM and PC
# Copyrith(C) 2012-2022 HQDigital Inc.

OBJS = ./*.o
all		: ALL
clean	: CLEAN
arm		: ARM
pc		: X86

ALL:
	make -f makefile.lib chip=gcc

3512:
	make -f makefile.lib chip=3512
	
3515:
	make -f makefile.lib chip=3515

3516:
	make -f makefile.lib chip=3516

3516c:
3518:
	make -f makefile.lib chip=3518
test1:
	echo $(LDFLAGS)
CLEAN:
	rm -f app_sample *.o
