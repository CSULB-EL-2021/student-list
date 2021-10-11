#  Name Emile LEPETIT
#  Class (CECS 282-01)
#  Project Name (Prog 3 – Structs and Pointers)
#  Due Date (10/11/2021)
#  I certify that this program is my own original work. I did not copy any part of this program from
#  any other source. I further certify that I typed each and every line of code in this program.

CXX			=	g++

NAME		=	prog3

RM			=	rm -f

CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	-Werror -Wall -Wextra

SRCS		=	./main.cpp 			\
				./myDate.cpp		\
				./studentList.cpp	\

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)
