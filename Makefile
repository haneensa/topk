TARGET = topk # executable with this name

CC = g++ # compiler
LINKER = g++ -o
CFLAGS = -g -O3 -std=c++11 -Wall -I. # Compiling flags
LFLAGS = -Wall

SRCDIR = src
OBJDIR = obj

SOURCES := $(wildcard $(SRCDIR)/*.cc)
OBJECTS := $(SOURCES:$(SRCDIR)%.cc=$(OBJDIR)%.o)
rm = rm -rf


# target: dependencies
# [tab]	<commands>

$(TARGET): build $(OBJECTS)
	$(LINKER) $@ $(LFLAGS) $(OBJECTS) 
	@echo "Linking complete."
	
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@ 
	@echo "Compiled"$<"successfully."
build:
	@mkdir -p obj

clean:
	@$(rm) $(OBJDIR) 
	@echo "Cleanup complete."

.PHONY: remove
remove: clean
	@$(rm) $(OBJDIR) $(TARGET)
	@echo "Executable removed."
