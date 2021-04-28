BIN=bin
LIB=lib

hepsi: onislem derle calistir
onislem:
	@mkdir -p $(LIB)
	gcc -I ./include/ -o ./$(LIB)/message.o -c ./src/message.c
derle:	
	@mkdir -p $(BIN)
	gcc -I ./include/ -o ./$(BIN)/output ./$(LIB)/message.o ./src/main.c
calistir:
	./bin/output