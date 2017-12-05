CC	= g++ -ldl -pthread -lssl -lcrypto -I${HOME}/usr/local/ssl/include -L${HOME}/usr/local/ssl/lib
#CC	= g++ -ldl -pthread -lssl -lcrypto -I/accounts/facstaff/hauschildm/usr/local/ssl/include -L/accounts/facstaff/hauschildm/usr/local/ssl/lib
DEBUG = -g
TARGET	= proj1
OBJS	= proj1.o

$(TARGET):	$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

proj1.o: proj1.cpp
	$(CC) -c proj1.cpp

clean:
	rm -f *.o $(TARGET) passwd*
