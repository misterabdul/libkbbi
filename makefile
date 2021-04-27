BIN := libkbbi.so
TST := test

SRCDIR := src
TSTDIR := test
OBJDIR := obj
BINDIR := bin

CFLAGS := -Wall -Wextra -g
SFLAGS := -fPIC -shared
TFLAGS := -ldl

BIN_SRCS := $(shell find $(SRCDIR) -name *.c)
BIN_OBJS := $(subst $(SRCDIR)/,$(SRCDIR)_,$(BIN_SRCS:%=$(OBJDIR)/%.o))
TST_SRCS := $(shell find $(TSTDIR) -name *.c)
TST_OBJS := $(subst $(TSTDIR)/,$(TSTDIR)_,$(TST_SRCS:%=$(OBJDIR)/%.o))

all: $(BINDIR)/$(BIN)

check: $(BINDIR)/$(TST) $(BINDIR)/$(BIN)
	@./$(BINDIR)/$(TST)

clean:
	@$(RM) -r $(OBJDIR)/*
	@$(RM) -r $(BINDIR)/*

# Link the main binary
$(BINDIR)/$(BIN): $(BIN_OBJS)
	@echo LINK $(BIN)
	@$(CC) $(BIN_OBJS) -o $@ $(CFLAGS) $(SFLAGS)

# Link the test binary
$(BINDIR)/$(TST): $(TST_OBJS)
	@echo LINK $(TST)
	@$(CC) $(TST_OBJS) -o $@ $(CFLAGS) $(TFLAGS)

# Compile each main source code
$(OBJDIR)/$(SRCDIR)_%.c.o: $(SRCDIR)/%.c
	@echo CC $<
	@$(CC) -c $< -o $@ $(CFLAGS) $(SFLAGS)

# Compile each test source code
$(OBJDIR)/$(TSTDIR)_%.c.o: $(TSTDIR)/%.c
	@echo CC $<
	@$(CC) -c $< -o $@ $(CFLAGS) $(TFLAGS)
