CC=gcc
LIB=lib
FDR=libfdr
EXE=executable

make: object build

object:
	@mkdir -p $(LIB)
	$(CC) -o ./$(LIB)/fields.o -c ./$(FDR)/fields.c
	$(CC) -o ./$(LIB)/jrb.o -c ./$(FDR)/jrb.c
	$(CC) -o ./$(LIB)/jval.o -c ./$(FDR)/jval.c
	$(CC) -o ./$(LIB)/jsonparser.o -c ./jsonparser.c
	$(CC) -o ./$(LIB)/encoder.o -c ./encoder.c
	$(CC) -o ./$(LIB)/decoder.o -c ./decoder.c
	$(CC) -o ./$(LIB)/trim.o -c ./trim.c

build:	
	$(CC) -o ./kripto ./$(LIB)/fields.o ./$(LIB)/jrb.o ./$(LIB)/jval.o ./$(LIB)/jsonparser.o ./$(LIB)/encoder.o ./$(LIB)/decoder.o ./$(LIB)/trim.o main.c

clean: 
	rm -rf lib kripto

cleanall: clean
	rm -rf .kilit encripted decripted *.txt ornek_metin

run : clean make
	./kripto -e ornek_metin encripted
	./kripto -d encripted decripted

testbuild: 
	@mkdir -p ./tests/$(EXE)	
	$(CC) ./tests/trim_test.c -I. -Wl,--wrap=trim -o ./tests/$(EXE)/trim_test

test: testbuild 
	./tests/executable/trim_test --cester-verbose