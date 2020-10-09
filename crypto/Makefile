CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -ggdb3 -c

SRC = ec_create.c ec_to_pub.c ec_from_pub.c ec_save.c ec_load.c ec_sign.c ec_verify.c sha256.c
OBJS = $(SRC:.c=.o)
NAME = libhblk_crypto.a

.PHONY: clean oclean

#clean:
#	rm *~ $(NAME)
#
#oclean:
#	rm $(OBJS)

libhblk_crypto.a: hblk_crypto.h $(OBJS)
	ar rcs $(NAME) $(OBJS)
