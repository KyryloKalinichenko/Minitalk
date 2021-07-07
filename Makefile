SRCS_S = 	server.c \
			atoi.c \
			itoa.c \
			main.c \

SRCS_C =	client.c \
			atoi.c \
			itoa.c \

OBJS_S			= $(SRCS_S:.c=.o)
OBJS_C			= $(SRCS_C:.c=.o)

RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.

CLIENT = client
SERVER = server

all:		$(SERVER) $(CLIENT)

$(SERVER): $(OBJS_S)
			gcc ${CFLAGS} -o ${SERVER} ${OBJS_S}

$(CLIENT): $(OBJS_C)
			gcc ${CFLAGS} -o ${CLIENT} ${OBJS_C}

clean:
				$(RM) $(OBJS_S) $(OBJS_C)

fclean:			clean
				$(RM) $(SERVER) $(CLIENT)

re:				fclean $(SERVER) $(CLIENT)

.PHONY:			all clean fclean re

# -fsanitize=address