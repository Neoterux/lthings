CC=gcc
LDFLAGS += 
CFLAGS += 
BIN=prog_main
TEST_ARGS+=-h --help -o --out

all: exe clean run
	
check_debug:
	@echo "CFLAGS: " ${CFLAGS};
	@echo "LDFLAGS: " ${LDFLAGS};
	@echo "CC: " ${CC};
	

%.o: %c
	@echo "Compiling things...\n"
	${CC} ${CFLAGS} ${LDFLAGS} -c $< 

exe: main.o
	@echo "Linking all ..."
	${CC} -o ${BIN} main.o

run:
	./${BIN} ${TEST_ARGS}

.PHONY: clean
clean:
	@rm *.o
