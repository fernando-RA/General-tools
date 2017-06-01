
# executable
TARGET   = library
CC       = gcc

# compiling flags
CFLAGS   = -Wall -I. -lm
LINKER   = gcc -o

# linking flags
LFLAGS   = -I'lib' -Pedantic -Wall -Ansi

# directories
SRCDIR   = src
LIBDIR	 = lib
OBJDIR   = obj
BINDIR   = bin

# paths
SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(LIBDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIBRARY  := $(INCLUDES:$(LIBDIR)/%.h)
rm       = rm -f

# linking rules
$(BINDIR)/$(TARGET): $(OBJECTS)
		@$(LINKER) $@ $(CFLAGS) $(OBJECTS) -lm
		@echo "Linking complete!"

# compiling rules
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Compiled "$<" successfully!"

# general rules
run:
		./$(BINDIR)/$(TARGET)

.PHONY: clean
clean:
		@$(rm) $(OBJECTS)
		@echo "Cleanup complete!"

.PHONY: remove
remove: clean
		@$(rm) $(BINDIR)/$(TARGET)
		@echo "Executable removed!"
