CC = gcc
LIB=lib
FDR=libfdr

hepsi: onislem derle
onislem:
	@mkdir -p $(LIB)
	$(CC) -I ./include/ -o ./$(LIB)/fields.o -c ./$(FDR)/fields.c
	$(CC) -I ./include/ -o ./$(LIB)/jrb.o -c ./$(FDR)/jrb.c
	$(CC) -I ./include/ -o ./$(LIB)/jval.o -c ./$(FDR)/jval.c
	$(CC) -I ./include/ -o ./$(LIB)/jsonparser.o -c ./src/jsonparser.c
	$(CC) -I ./include/ -o ./$(LIB)/encoder.o -c ./src/encoder.c
	$(CC) -I ./include/ -o ./$(LIB)/decoder.o -c ./src/decoder.c
	$(CC) -I ./include/ -o ./$(LIB)/trim.o -c ./src/trim.c
derle:	
	$(CC) -I ./include/ -o ./kripto ./$(LIB)/fields.o ./$(LIB)/jrb.o ./$(LIB)/jval.o ./$(LIB)/jsonparser.o ./$(LIB)/encoder.o ./$(LIB)/decoder.o ./$(LIB)/trim.o ./src/main.c
