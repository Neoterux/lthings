CC       := clang
# Sources configuration
BIN      := client
SRC_D    := src
OUT_D    := build
SRC_F    := $(wildcard $(SRC_D)/*.c)	# Source files
HEADERS  := $(wildcard $(SRC_D)/*.h)	# Header files
INCLUDES := $(patsubst %.h,-I%.h,$(HEADERS))	# Include header files flags for cpp
OBJS     := $(patsubst $(SRC_D)/%.c,$(OUT_D)/%.o,$(SRC_F))
# Compile specific flags
CPPFLAGS := -I$(SRC_D)
# !! CFLAGS are custom, change to work with your CPU arquitechture
CFLAGS   := -march=znver3 -mtune=znver3 -pipe -Wall -std=c17
LDFLAGS  := -Wl,O4
DFLAGS   := 
CPPFLAGS := $(CPPFLAGS)
# Extra
dir_guard=@mkdir -p $(@D)

.PHONY: all
all: $(BIN)

# Link all the object files
$(BIN): $(OBJS)
	@ echo Linking object files...
	$(CC) -o $(BIN) $(OBJS)

$(OUT_D)/%.o: $(SRC_D)/%.c
	$(dir_guard)
	$(CC) $(CFLAGS) $(LDFLAGS) $(DFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: debug
debug: CFLAGS=-O0 -pipe -Wall
debug: DFLAGS=-g
debug: clean all

.PHONY: sanitize
sanitize: DFLAGS=-fsanitize=address -fno-omit-fram-pointer -Wno-format-security
sanitize: clean all


.PHONY: clean
clean:
	rm -rf $(OUT_D) &> /dev/null
	rm -f $(BIN) &> /dev/null
