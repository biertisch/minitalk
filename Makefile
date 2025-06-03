#alternative if only one .c file per executable: 
#EXE = server client
#SRCS = server.c client.c
#OBJS = $(SRCS:.c=.c)
#all: $(EXE)
#%: %.o $(LIBFT)
#	$(CC) $< -o $@ $(LIBFT)

SRC_DIR = src/
OBJ_DIR = obj/
LIB_DIR = lib/
LIB = $(LIB_DIR)libft.a

SERVER = server
SERVER_SRCS = $(SRC_DIR)server.c
SERVER_OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SERVER_SRCS))

CLIENT = client
CLIENT_SRCS = $(SRC_DIR)client.c
CLIENT_OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(CLIENT_SRCS))

EXE = $(SERVER) $(CLIENT)
OBJS = $(SERVER_OBJS) $(CLIENT_OBJS)

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -I$(LIB_DIR)include
RM = rm -rf

all: obj $(LIB) $(EXE)

obj:
	mkdir -p $(OBJ_DIR)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o $@ $(LIB)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o $@ $(LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(EXE)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re