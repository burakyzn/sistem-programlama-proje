CC=gcc
LIB=lib
FDR=libfdr
EXE=executable
OBJS = ./libfdr/fields.o ./libfdr/jval.o ./libfdr/jrb.o

make: libfdr.a object build

object: 
	@mkdir -p $(LIB)
	$(CC) -o ./$(LIB)/jsonparser.o -c ./jsonparser.c
	$(CC) -o ./$(LIB)/encoder.o -c ./encoder.c
	$(CC) -o ./$(LIB)/decoder.o -c ./decoder.c
	$(CC) -o ./$(LIB)/trim.o -c ./trim.c

libfdr.a: $(OBJS)
	ar ru ./libfdr/libfdr.a $(OBJS)
	ranlib ./libfdr/libfdr.a 

build:	
	$(CC) -o ./kripto ./$(LIB)/jsonparser.o ./$(LIB)/encoder.o ./$(LIB)/decoder.o ./$(LIB)/trim.o ./$(FDR)/libfdr.a main.c

clean: 
	rm -rf lib kripto

cleanall: clean
	rm -rf .kilit encripted decripted *.txt ornek_metin

run : clean make
	./kripto -e ornek_metin encripted
	./kripto -d encripted decripted

testclean:
	rm -rf ./tests/executable

testbuild: 
	@mkdir -p ./tests/$(EXE)	
	$(CC) ./tests/trim_test.c -I. -Wl,--wrap=trim -o ./tests/$(EXE)/trim_test
	$(CC) ./tests/jsonparser_test.c -I. -Wl,--wrap=parse_json_file -o ./tests/$(EXE)/jsonparser_test

test: testclean testbuild 
	./tests/executable/trim_test --cester-verbose
	./tests/executable/jsonparser_test --cester-verbose
