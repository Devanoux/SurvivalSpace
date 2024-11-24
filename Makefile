NAME = ft_shmup
BUILD_FOLDER = .build

FILES =	main.c \
		game.c \
		utils.c \
		player.c \
		asteroid.c \
		map.c \
		time.c \
		display.c \
		screen.c \
		free.c \
		init.c \
		enemy.c

OBJS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.d))

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP

MAKEFLAGS += --no-print-directory

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJS)
	cc -lncursesw $(CFLAGS) $(OBJS) -o $(NAME) 

$(BUILD_FOLDER)/%.o: %.c
	@mkdir -p $(BUILD_FOLDER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean 
	$(MAKE) all

-include $(DEPS)
