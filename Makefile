SRC_DIR = src/
OBJ_DIR = obj/
LIB_DIR = lib/

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -I$(LIB_DIR)include
RM = rm -rf

LIB = $(LIB_DIR)libft.a

SERVER = server
SERVER_SRC = $(SRC_DIR)$(SERVER).c
SERVER_OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SERVER_SRC))

CLIENT = client
CLIENT_SRC = $(SRC_DIR)$(CLIENT).c
CLIENT_OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(CLIENT_SRC))

SERVER_B = server_bonus
SERVER_B_SRC = $(SRC_DIR)$(SERVER_B).c
SERVER_B_OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SERVER_B_SRC))

CLIENT_B = client_bonus
CLIENT_B_SRC = $(SRC_DIR)$(CLIENT_B).c
CLIENT_B_OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(CLIENT_B_SRC))

all: obj $(LIB) $(SERVER) $(CLIENT)

obj:
	mkdir -p $(OBJ_DIR)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(SERVER_OBJ) -o $@ $(LIB)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) -o $@ $(LIB)

bonus: obj $(LIB) $(SERVER_B) $(CLIENT_B)

$(SERVER_B): $(SERVER_B_OBJ)
	$(CC) $(SERVER_B_OBJ) -o $@ $(LIB)

$(CLIENT_B): $(CLIENT_B_OBJ)
	$(CC) $(CLIENT_B_OBJ) -o $@ $(LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re