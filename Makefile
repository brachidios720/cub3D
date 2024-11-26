
NAME = cub3D

CC = cc

FLAGS = -g -Wall -Wextra -Werror

MLX_DIR = ./include/mlx
MLX_LIB = ${MLX_DIR}/libmlx.a
MLX_FLAG = -lm -lmlx -lX11 -lXext

LIBFT_DIR = ./libft-complete
LIBFT_LIB = ${LIBFT_DIR}/libft_complete.a
LIBFT_FLAG = -lft_complete

INCLUDES = -I ./Includes/

PARSING_SOURCES = ./Parsing/main.c\
					./Parsing/init.c
					
RAYCASTING_SOURCES = ./Raycasting/raycasting_entry.c

PARSING_OBJ_PATH = obj/Parsing/
RAYCASTING_OBJ_PATH = obj/Raycasting/

PARSING_OBJS = ${PARSING_SOURCES:.c=.o}
PARSING_OBJS := $(addprefix ${PARSING_OBJ_PATH}, $(notdir ${PARSING_OBJS}))

RAYCASTING_OBJS = ${RAYCASTING_SOURCES:.c=.o}
RAYCASTING_OBJS := $(addprefix ${RAYCASTING_OBJ_PATH}, $(notdir ${RAYCASTING_OBJS}))

all : ${PARSING_OBJ_PATH} ${RAYCASTING_OBJ_PATH} ${NAME}

${PARSING_OBJ_PATH}:
	mkdir -p ${PARSING_OBJ_PATH}

${RAYCASTING_OBJ_PATH}:
	mkdir -p ${RAYCASTING_OBJ_PATH}

${NAME} : ${PARSING_OBJS} ${RAYCASTING_OBJS} ${MLX_LIB} ${LIBFT_LIB}
	${CC} ${FLAGS} ${PARSING_OBJS} ${RAYCASTING_OBJS} \
	-L${MLX_DIR} -L${LIBFT_DIR} -o $@ ${MLX_FLAG} ${LIBFT_FLAG}

${MLX_LIB} :
	${MAKE} -C ${MLX_DIR}

${LIBFT_LIB} :
	${MAKE} -C ${LIBFT_DIR}

${PARSING_OBJ_PATH}%.o : ./Parsing/%.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

${RAYCASTING_OBJ_PATH}%.o : ./Raycasting/%.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

clean : 
	${MAKE} clean -C ${MLX_DIR}
	${MAKE} clean -C ${LIBFT_DIR}
	${RM} ${PARSING_OBJS} ${RAYCASTING_OBJS}
	${RM} -r obj/

fclean : clean
	${MAKE} fclean -C ${LIBFT_DIR}
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
