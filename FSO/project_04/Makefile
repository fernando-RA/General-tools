
# project name (generate executable with this name)
TARGET   = library
CC       = gcc

# compiling flags
CFLAGS   = -Wall -I. -I'lib'
LINKER   = gcc -o

# linking flags
LFLAGS   =  -pthread -I'lib' -Pedantic -Wall -Ansi

# change these to proper directories where each file should be
SRCDIR   = src
LIBDIR	 = lib
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(LIBDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIBRARY  := $(INCLUDES:$(LIBDIR)/%.h)
rm       = rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
		@$(LINKER) $@ $(CFLAGS) $(OBJECTS)
		@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
		@$(rm) $(OBJECTS)
		@echo "Cleanup complete!"

.PHONY: remove
remove: clean
		@$(rm) $(BINDIR)/$(TARGET)
		@echo "Executable removed!"

run:
		./$(BINDIR)/$(TARGET)
