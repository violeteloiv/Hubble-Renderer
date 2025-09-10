# MY BB FIXED IT FOR ME, TY SNEHA <3

# Compiler and flags
CC      := gcc
CFLAGS  := -Wall -Wextra -fPIC -Ihubble/include -Ilibraries/glfw/include -IC:\VulkanSDK\1.4.321.1\Include
LDFLAGS := -L. -Llibraries/glfw/lib-mingw-w64 -LC:\VulkanSDK\1.4.321.1\Lib -lglfw3 -lvulkan-1 -lgdi32

# Project structure
HUBBLE_SRC   := $(wildcard hubble/src/*.c)
HUBBLE_OBJ   := $(HUBBLE_SRC:.c=.o)
HUBBLE_LIB   := libhubble.dll
HUBBLE_LINK  := -lhubble

TEST_SRC     := $(wildcard test/src/*.c)
TEST_OBJ     := $(TEST_SRC:.c=.o)
TEST_BIN     := test.exe

# Default target
all: $(HUBBLE_LIB) $(TEST_BIN)

# Build shared library
$(HUBBLE_LIB): $(HUBBLE_OBJ)
	$(CC) -shared -o $@ $^ $(LDFLAGS)

# Build test executable
$(TEST_BIN): $(TEST_OBJ) $(HUBBLE_LIB)
	$(CC) -o $@ $(TEST_OBJ) $(HUBBLE_LINK) $(LDFLAGS)

# Object file rules
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	$(RM) hubble/src/*.o test/src/*.o $(HUBBLE_LIB) $(TEST_BIN)

# Run test
run: $(TEST_BIN)
	LD_LIBRARY_PATH=. ./$(TEST_BIN)

.PHONY: all clean run