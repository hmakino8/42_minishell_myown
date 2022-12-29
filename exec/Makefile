NAME	:=	exec.a
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
SRCDIR	:=	./
AR		:=	ar
ARFLAFS	:=	-rcs
RM		:=	rm -rf
SOURCES	:=
OBJDIR	:=	./obj
OBJECTS	:=	$(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.c=.o)))
DEPENDS	:=	$(OBJECTS:.o:=.d)
INCLUDE	:=	-I ../../libft/includes
#Message
RED		:=	\033[1;31m
GREEN	:=	\033[1;32m
YELLOW	:=	\033[1;33m
DEFAULT	:=	\033[0m

NAME_MSG := " $(GREEN)Compile $(NAME)$(DEFAULT)"
CLEAN_MSG := " $(YELLOW)Delete ./srcs/parser/obj$(DEFAULT)"
FCLEAN_MSG := " $(RED)Delete $(NAME)$(DEFAULT)"

$(NAME): $(OBJECTS)
	@$(AR) $(ARFLAFS) $(NAME) $(OBJECTS)
	@echo $(NAME_MSG)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@-mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
	@$(RM) $(OBJDIR)
	@echo $(CLEAN_MSG)

.PHONY: fclean
fclean:	clean
	@$(RM) $(NAME)
	@echo $(FCLEAN_MSG)

.PHONY: re
re: fclean all

.PHONY: test
test: all
	$(CC) $(CFLAGS) -o test $(NAME) test.c
	./test
