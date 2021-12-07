CC=gcc
LDFLAGS=-lm
CFLAGS?=-O2 -pipe -march=x86-64 -mtune=generic
BIN=avgc
OBJS=main.o
ODIR=${HOME}/.local/bin

compile: $(OBJS)
	@echo "Linking object files"
	${CC} ${OBJS} -o ${BIN}


%.o: %.c
	@echo "compiling file: " $<
	${CC} ${CFLAGS} -c $< ${LDFLAGS}

.PHONY: clean
clean:
	rm *.o ${BIN}

.PHONY: install
install: compile
	@echo "Installing into: " ${ODIR}
	@cp ${BIN} ${ODIR}
	@echo "Installed"
