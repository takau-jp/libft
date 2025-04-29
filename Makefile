# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 21:27:03 by stanaka2          #+#    #+#              #
#    Updated: 2025/04/29 16:40:02 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./includes
SRCDIR = srcs
SRCS = ${addprefix ${SRCDIR}/, \
	ft_bzero.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	}
B_SRCS = ${addprefix ${SRCDIR}/, \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
}
OBJDIR = objs
OBJS = ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.o}}}
B_OBJS	= ${addprefix ${OBJDIR}/, ${notdir ${B_SRCS:.c=.o}}}

DEPSFLAGS	= -MMD
DEPS	= ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.d}}}
B_DEPS	= ${addprefix ${OBJDIR}/, ${notdir ${B_SRCS:.c=.d}}}

ifeq ($(MAKECMDGOALS), bonus)
OBJS	+= $(B_OBJS)
DEPS	+= $(B_DEPS)
endif

${NAME} : ${OBJS}
	ar rcs $@ $?

${OBJDIR}:
	-mkdir -p ${OBJDIR}

${OBJDIR}/%.o: ${SRCDIR}/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

# ${OBJDIR}/%.o: ${SRCDIR}/ctype/%.c | ${OBJDIR}
# 	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

# ${OBJDIR}/%.o: ${SRCDIR}/stdio/%.c | ${OBJDIR}
# 	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

# ${OBJDIR}/%.o: ${SRCDIR}/stdio/printf/%.c | ${OBJDIR}
# 	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

# ${OBJDIR}/%.o: ${SRCDIR}/stdlib/%.c | ${OBJDIR}
# 	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

# ${OBJDIR}/%.o: ${SRCDIR}/string/%.c | ${OBJDIR}
# 	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

# ${OBJDIR}/%.o: ${SRCDIR}/lst/%.c | ${OBJDIR}
# 	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

all: ${NAME}

bonus: ${NAME}

clean:
	rm -f ${OBJS} ${B_OBJS} ${DEPS} ${B_DEPS}

fclean: clean
	rm -rf $(NAME) ${OBJDIR}

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re
