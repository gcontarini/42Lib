############## CORE FILES ##############
CORE 	=	ft_atoi.c			\
			ft_bzero.c			\
			ft_calloc.c			\
			ft_intlen.c			\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_itoa.c			\
			ft_itoa_mem.c		\
			ft_longlen_base.c	\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memset.c			\
			ft_putchar_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_putstr_fd.c		\
			ft_split.c			\
			ft_strchr.c			\
			ft_strdup.c			\
			ft_striteri.c		\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strlen.c			\
			ft_strmapi.c		\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_strtrim.c		\
			ft_substr.c			\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_uintlen.c		\
			ft_uintlen_base.c	\
			ft_ulonglen_base.c	\
			ft_ultoa_membase.c	\
			ft_utoa_mem.c		\
			ft_utoa_membase.c

########### LINKED LIST FILES ###########
LLST	=	ft_lstadd_back.c	\
			ft_lstadd_front.c	\
			ft_lstclear.c		\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstlast.c		\
			ft_lstmap.c			\
			ft_lstnew.c			\
			ft_lstsize.c

############### GNL FILES ###############
GNL		=	get_next_line.c

############## PRINTF FILES #############
PTF		=	ft_printf.c			\
			ftptf_args.c		\
			ftptf_char.c		\
			ftptf_flush.c		\
			ftptf_int.c			\
			ftptf_jptab.c		\
			ftptf_lowhex.c		\
			ftptf_memerror.c	\
			ftptf_perc.c		\
			ftptf_ptr.c			\
			ftptf_queue.c		\
			ftptf_str.c			\
			ftptf_uint.c		\
			ftptf_uphex.c		\

############## STACK FILES #############
STK		=	ft_istkclean.c	\
			ft_istkpeek.c	\
			ft_istkprint.c	\
			ft_istksort.c	\
			ft_stkclean.c	\
			ft_stkcpy.c		\
			ft_stkcpyn.c	\
			ft_stkget.c		\
			ft_stklen.c		\
			ft_stkpop.c		\
			ft_stkposh.c	\
			ft_stkpush.c	\
			ft_stkrot.c		\
			ft_stkrpush.c	\
			ft_stkrrot.c	\
			ft_stkstart.c	\
			ft_stkswap.c	\
			ft_stkswapn.c

################ PATHS #################
INC	= -I includes/
POBJS	= obj

############### ALL OBJS ###############
OBJS 	= 	$(addprefix $(POBJS)/, $(CORE:.c=.o))
OBJS 	+= 	$(addprefix $(POBJS)/, $(LLST:.c=.o))
OBJS 	+= 	$(addprefix $(POBJS)/, $(PTF:.c=.o))
OBJS 	+= 	$(addprefix $(POBJS)/, $(GNL:.c=.o))
OBJS 	+= 	$(addprefix $(POBJS)/, $(STK:.c=.o))

############### TARGET #################
NAME 	= 	libft.a

############# COMPILER OPTS ############
CC 	= 	gcc 
CFLAGS	= 	-Wall -Werror -Wextra
RM	= 	rm -f
AR	=	ar rcs

################ RULES #################
$(POBJS)/%.o : */%.c
	@mkdir -p $(POBJS)/
	$(CC) $(CFLAGS) -c $(INC) $< -o $@

$(NAME)	: $(OBJS)
	$(AR) $@ $^

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re 
