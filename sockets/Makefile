server_SRC :=server
server_BIN :=server
client_SRC :=client
client_BIN :=client
PORT := 9234

.PHONY: all
all: server client

.PHONY: test
test: all 
	@ echo Executing server in background...
	./$(server_BIN)_exe -p $(PORT) &
	@ echo Running client
	./$(client_BIN)_exe -p $(PORT)


.PHONY: server client
server client:
	@echo Making $@ executable
	make -C ./$($@_SRC) clean all
	@cp $($@_SRC)/$($@_BIN) ./$($@_BIN)_exe

.PHONY: clean
clean:
	@echo Cleaning executables
	@rm -f $(server_BIN)_exe $(client_BIN)_exe
	@echo Cleaning server project directory
	@make -C ./$(server_SRC) clean
	@echo Cleaning client project directory
	@make -C ./$(client_SRC) clean

