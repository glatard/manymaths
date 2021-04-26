wrap-mpfr: wrap-mpfr.c
	gcc -Wall -fPIC --shared wrap-mpfr.c -lm -lmpfr -o mpfr_wrap.so
wrap: wrap.c
	test -f $${LIB_PATH} && gcc -fPIC -DLIB_PATH=\"$${LIB_PATH}\" -shared -ldl wrap.c -o $${LIB_NAME}_wrap.so
clean:
	rm *.o *.so test -Rf