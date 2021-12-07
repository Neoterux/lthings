CC := gcc
CFLAGS ?=
LDFLAGS :=
CPPFLAGS :=
NORDR_BIN := no_rdrand_test
RDR_BIN := yes_rdrand_test

all: $(NORDR_BIN) $(RDR_BIN)

$(NORDR_BIN): CFLAGS =-pipe -O2
$(NORDR_BIN): test.c
	$(CC) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS) $< -o $@

$(RDR_BIN): CFLAGS = -march=znver3 -mtune=znver3 -pipe -O2
$(RDR_BIN): test.c
	$(CC) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS) $< -o $@

time: clean all
	@echo Timing $(NORDR_BIN)
	@time ./$(NORDR_BIN)
	@echo ---------------------------------
	@echo Timing $(RDR_BIN)
	@time ./$(RDR_BIN)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean: 
	rm -f $(NORDR_BIN) $(RDR_BIN) *.o
