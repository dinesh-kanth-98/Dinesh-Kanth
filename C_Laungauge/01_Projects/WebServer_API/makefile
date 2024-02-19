CC = gcc
CFLAGS = -Wall -g
TARGET = bin/webApiServer
OBJ_DIR = obj
BIN_DIR = bin
WEB_SERVER_DIR = WebServer
SETTINGS_DIR = Settings
COMMON_INCLUDE_DIR = CommonInclude

# List of source files in the WebServer directory
WEB_SERVER_SRCS = $(wildcard $(WEB_SERVER_DIR)/*.c)
WEB_SERVER_OBJS = $(patsubst $(WEB_SERVER_DIR)/%.c, $(OBJ_DIR)/%.o, $(WEB_SERVER_SRCS))

# List of source files in the Settings directory
SETTINGS_SRCS = $(wildcard $(SETTINGS_DIR)/*.c)
SETTINGS_OBJS = $(patsubst $(SETTINGS_DIR)/%.c, $(OBJ_DIR)/%.o, $(SETTINGS_SRCS))

# List of common header files
COMMON_HEADERS = $(wildcard $(COMMON_INCLUDE_DIR)/*.h)

# All object files
OBJS = $(WEB_SERVER_OBJS) $(SETTINGS_OBJS)

# Include directories
INC_DIRS = -I$(WEB_SERVER_DIR) -I$(SETTINGS_DIR) -I$(COMMON_INCLUDE_DIR)

# Compilation and linking
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Compile each source file into an object file for WebServer
$(OBJ_DIR)/%.o: $(WEB_SERVER_DIR)/%.c $(COMMON_HEADERS)
	$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

# Compile each source file into an object file for Settings
$(OBJ_DIR)/%.o: $(SETTINGS_DIR)/%.c $(COMMON_HEADERS)
	$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

# Create directories
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(TARGET)

