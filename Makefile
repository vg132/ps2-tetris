EE_BIN = bin/tetris.elf
EE_OBJS = src/ps2control.o src/text.o src/field.o src/player.o src/control.o src/game.o src/draw.o src/tetris.o src/main.o \
					graphics/mback.o graphics/block1.o graphics/block2.o graphics/block3.o graphics/block4.o graphics/block5.o graphics/block6.o graphics/block7.o graphics/block8.o graphics/logo2.o
EE_INCS += -I/home/viktor/dev/ps2/tetris/include
EE_LDFLAGS := -s

all : $(EE_BIN) 

graphics/mback.s:
	bin2s graphics/mback.iif graphics/mback.s mback
graphics/block1.s:
	bin2s graphics/block1.iif graphics/block1.s block1
graphics/block2.s:
	bin2s graphics/block2.iif graphics/block2.s block2
graphics/block3.s:
	bin2s graphics/block3.iif graphics/block3.s block3
graphics/block4.s:
	bin2s graphics/block4.iif graphics/block4.s block4
graphics/block5.s:
	bin2s graphics/block5.iif graphics/block5.s block5
graphics/block6.s:
	bin2s graphics/block6.iif graphics/block6.s block6
graphics/block7.s:
	bin2s graphics/block7.iif graphics/block7.s block7
graphics/block8.s:
	bin2s graphics/block8.iif graphics/block8.s block8
graphics/logo2.s:
	bin2s graphics/logo2.iif graphics/logo2.s logo

include $(LIBITO)/Makefile.prefab