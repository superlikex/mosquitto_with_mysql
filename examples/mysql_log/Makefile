CFLAGS=-Wall -ggdb
LDFLAGS=../../lib/libmosquitto.so.1 -lmysqlclient -lm

.PHONY: all clean

all : mosquitto_mysql_log

mosquitto_mysql_log : mysql_log.o cjson.o
	${CC} $^ -o $@ ${LDFLAGS}

mysql_log.o : mysql_log.c cJSON.h
	${CC} -c $< -o $@ ${CFLAGS} -I../../lib

cjson.o : cjson.c cJSON.h
	${CC} -c $< -o $@

clean : 
	-rm -f *.o mosquitto_mysql_log
