SRCS = main.cpp bin/stat.cpp bin/point.cpp
TARG = main
CC = g++
OPTS = -Wall -O
LIBS = -lm
# this translates .c files in src list to .o’s
OBJS = $(SRCS:.cpp=.o)
all: $(TARG)
	
# this generates the target executable
$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS)
# this is a generic rule for .o files
%.o: %.cpp
	$(CC) $(OPTS) -c $< -o $@
# and finally, a clean line
clean:
	rm -f $(OBJS) $(TARG)