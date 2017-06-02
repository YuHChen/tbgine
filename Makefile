# specify directory names of source, test, and build directories
SRC_DIR := src
TEST_DIR := test
BUILD_DIR := build

# C++ files to build
SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.cpp')
TEST_FILES := common/Player.cpp \
	common/GameState.cpp

# object files are C++ files with .cpp extension replaced by .o
# object files are placed into build directory
OBJ_FILES := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))
TESTS := $(patsubst %.cpp,$(BUILD_DIR)/$(TEST_DIR)/%Test, $(TEST_FILES))

# dependency files object files with .o extension replaced by .depends
# these files contain dependencies of the object file
DEPENDS := $(OBJ_FILES:.o=.depends)
DEPENDS += $(TESTS:Test=Test.depends)

# specify directory containing header files
INCLUDE_DIR := include

# specify compiler
CC = g++

# options for compiler
CFLAGS = -g -std=c++14 -Wall -Wextra -pedantic -Wfatal-errors

# options for preprocessor
CPPFLAGS = -I$(INCLUDE_DIR)

# pseudo-target to tell make not to check for the existence of the prerequisite
# files; this forces the prerequisites to always be remade even if there is a
# file having the same name as a prerequisite
.PHONY:	all tests clean

# phony target to build all 
all: $(OBJ_FILES)

# phony target to build all tests
tests: $(TESTS)

# phony target to run all tests
runtests: tests
	@for test in $(TESTS); do \
	echo "===== Running $$test ====="; \
	$$test; \
	echo; \
	done

# phony target to clean up generated files as well as emacs backup files
clean:
	find . -type f -name '*.o' -delete
	find . -type f -name '*.exe' -delete
	find . -type f -name '*.depends' -delete
	find . -type f -name '*~' -delete
	find . -type f -name '*#' -delete
	rm -rf $(BUILD_DIR)/$(SRC_DIR)/* $(BUILD_DIR)/$(TEST_DIR)/*

# rule to build object files
$(BUILD_DIR)/$(SRC_DIR)/%.o:	$(SRC_DIR)/%.cpp
	@echo "Compiling" $<
	@mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# rule to create dependencies file for .cpp file
$(BUILD_DIR)/$(SRC_DIR)/%.depends:	$(SRC_DIR)/%.cpp
	@mkdir -p "$(@D)"
	@$(CC) $(CPPFLAGS) -MM $< > $@

# rule to link test executable from test and source object files
$(BUILD_DIR)/$(TEST_DIR)/%Test:	$(BUILD_DIR)/$(TEST_DIR)/%Test.o $(BUILD_DIR)/$(SRC_DIR)/%.o
	@echo "Linking" $@
	$(CC) $^ -o $@

# rule to build test object files
$(BUILD_DIR)/$(TEST_DIR)/%.o:	$(TEST_DIR)/%.cpp
	@echo "Compiling" $<
	@mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

#rule to create dependencies file for test .cpp file
$(BUILD_DIR)/$(TEST_DIR)/%.depends:	$(TEST_DIR)/%.cpp
	@mkdir -p "$(@D)"
	@$(CC) $(CPPFLAGS) -MM $< > $@

# include all dependencies files
# the - suppresses warnings if dependencies file does not exist
-include $(DEPENDS)
