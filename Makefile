SERVER			=	server
CLIENT			=	client
SERVER_B		=	server_bonus
CLIENT_B		=	client_bonus

SERVER_FILES	=	$(SERVER)
CLIENT_FILES	=	$(CLIENT)
SERVER_B_FILES	=	$(SERVER_B)
CLIENT_B_FILES	=	$(CLIENT_B)

SRC_DIR			=	src/
OBJ_DIR			=	obj/
INC_DIR			=	include/
LIBFT_DIR		=	libft/

LIBFT_URL		=	https://github.com/biertisch/libft.git
LIBFT			=	$(LIBFT_DIR)libft.a

SERVER_SRC 		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SERVER_FILES)))
CLIENT_SRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CLIENT_FILES)))
SERVER_B_SRC	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SERVER_B_FILES)))
CLIENT_B_SRC	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(CLIENT_B_FILES)))

SERVER_OBJ 		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SERVER_FILES)))
CLIENT_OBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CLIENT_FILES)))
SERVER_B_OBJ	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SERVER_B_FILES)))
CLIENT_B_OBJ	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CLIENT_B_FILES)))

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g -I$(INC_DIR) -I$(LIBFT_DIR)$(INC_DIR)
LFLAGS			=	-L$(LIBFT_DIR) -lft
RM				=	rm -rf

SENTINEL		=	$(OBJ_DIR).compiled

all: $(SERVER) $(CLIENT)
	@cat banner.txt

bonus: $(SERVER_B) $(CLIENT_B)
	@cat banner.txt

$(SERVER): $(LIBFT) $(SERVER_OBJ)
	@echo "Linking executable..."
	@$(CC) $(SERVER_OBJ) $(LFLAGS) -o $@

$(CLIENT): $(LIBFT) $(CLIENT_OBJ)
	@echo "Linking executable..."
	@$(CC) $(CLIENT_OBJ) $(LFLAGS) -o $@

$(SERVER_B): $(LIBFT) $(SERVER_B_OBJ)
	@echo "Linking executable..."
	@$(CC) $(SERVER_B_OBJ) $(LFLAGS) -o $@

$(CLIENT_B): $(LIBFT) $(CLIENT_B_OBJ)
	@echo "Linking executable..."
	@$(CC) $(CLIENT_B_OBJ) $(LFLAGS) -o $@

$(LIBFT): | $(LIBFT_DIR)
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR) extra > /dev/null

$(LIBFT_DIR):
	@echo "Cloning libft..."
	@git clone --quiet $(LIBFT_URL) $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ): $(SENTINEL)

$(SENTINEL):
	@echo "Compiling object files..."
	@touch $@

clean:
	@echo "Removing object files..."
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null

fclean: clean
	@echo "Removing executable and libraries..."
	@$(RM) $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@$(RM) $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re