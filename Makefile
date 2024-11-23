NAME = ft_shmup
BUILD_FOLDER = .build

FILES =	main.c \
		game.c \
		utils.c \
		player.c \
		asteroid.c \
		map.c \
		init.c 

OBJS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.d))

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP

-include $(DEPS)

.PHONY: all bonus clean fclean re

all:	$(NAME)

$(NAME):	$(OBJS)
	cc -lncursesw $(OBJS) -o $(NAME) 

$(BUILD_FOLDER)/%.o: %.c
	@mkdir -p $(BUILD_FOLDER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean 
	$(MAKE) all
