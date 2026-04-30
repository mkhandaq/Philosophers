NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 
OBJS = $(SRCS:.c=.o)

HEADERS = philo.h

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re