TST := test

TSTDIR := test
OBJDIR := obj
BINDIR := bin

CFLAGS := -Wall -Wextra

TST_SRCS := $(shell find $(TSTDIR) -name *.c)
TST_OBJS := $(subst test/,test_,$(TST_SRCS:%=$(OBJDIR)/%.o))

# Link the main test binary
$(BINDIR)/$(TST): $(TST_OBJS) $(SQLITE_OBJS)
	@echo LINK $(TST)
	@$(CC) $(TST_OBJS) -o $@ $(CFLAGS)

# Compile each test source code
$(OBJDIR)/test_%.c.o: $(TSTDIR)/%.c
	@echo CC $<
	@$(CC) -c $< -o $@ $(CFLAGS) $(TFLAGS)

clean:
	rm -rf $(OBJDIR)/*
	rm -rf $(BINDIR)/*

check: $(BINDIR)/$(TST)
	@./$(BINDIR)/$(TST)
