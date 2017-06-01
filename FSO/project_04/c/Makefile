
# executable
TARGET   = library
CC       = gcc

# compiling flags
CFLAGS   = -Wall -I. -lm -ldl
LINKER   = gcc -o

# linking flags
LFLAGS   = -I'lib' -Pedantic -Wall -Ansi -shared -ldl

# directories
SRCDIR   = src
LIBDIR	 = lib
LIBSO		 = $(LIBDIR)/dynamic
OBJDIR   = obj
BINDIR   = bin

# paths
SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(LIBDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIBRARY  := $(INCLUDES:$(LIBDIR)/%.h)
rm        = rm -f

# linking rules
$(BINDIR)/$(TARGET): $(OBJECTS)
		@$(LINKER) $@ $(CFLAGS) $(OBJECTS) -ldl
		@echo "Linking complete!"

$(LIBSO)/libseno.so: $(OBJDIR) | $(LIBDIR)
	$(CC) $(CFLAGS) -shared $< -o $@

# compiling rules
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Compiled "$<" successfully!"

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
