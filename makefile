BIN=bin
LIB=lib

hepsi: onislem derle calistir
onislem:
	@mkdir -p $(LIB)
	gcc -I ./include/ -o ./$(LIB)/fields.o -c ./src/fields.c
	gcc -I ./include/ -o ./$(LIB)/jrb.o -c ./src/jrb.c
	gcc -I ./include/ -o ./$(LIB)/jval.o -c ./src/jval.c
	gcc -I ./include/ -o ./$(LIB)/jsonparser.o -c ./src/jsonparser.c
	gcc -I ./include/ -o ./$(LIB)/encoder.o -c ./src/encoder.c
derle:	
	@mkdir -p $(BIN)
	gcc -I ./include/ -o ./$(BIN)/output ./$(LIB)/fields.o ./$(LIB)/jrb.o ./$(LIB)/jval.o ./$(LIB)/jsonparser.o ./$(LIB)/encoder.o ./src/main.c
calistir:
	./bin/output
