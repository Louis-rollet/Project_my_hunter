##
## EPITECH PROJECT, 2022
## B-PSU-100-MPL-1-1-bsmyls-louis.rollet
## File description:
## Makefile
##

CC = gcc
SRC = $(wildcard *.c)
TARGET = my_hunter
OBJ = $(wildcard *~)
FLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm

$(TARGET) :
	$(CC) -o $(TARGET) $(SRC) $(FLAGS)

all :	$(TARGET)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET)

re : fclean all
