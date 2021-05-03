wrap-mpfr: wrap-mpfr.c
	gcc -Wall -fPIC --shared wrap-mpfr.c -DDEBUG=1 -lm -lmpfr -o mpfr_wrap.so
wrap: wrap.c
	test -f $${LIB_PATH} && gcc -fPIC -DDEBUG=1 -DLIB_PATH=\"$${LIB_PATH}\" -shared -ldl wrap.c -o $${LIB_NAME}_wrap.so
wrap-doubled: wrap-doubled.c
	test -f $${LIB_PATH} && gcc -fPIC -DDEBUG=1 -DLIB_PATH=\"$${LIB_PATH}\" -shared -ldl wrap-doubled.c -o $${LIB_NAME}_doubled_wrap.so
clean:
	rm *.o *.so test -Rf