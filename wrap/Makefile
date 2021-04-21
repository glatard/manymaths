wrap-mpfr: wrap-mpfr.c
	gcc -fPIC --shared wrap-mpfr.c -o mpfr_wrap.so
wrap: wrap.c
	gcc -fPIC -DLIB_PATH=\"$${LIB_PATH}\" --shared wrap.c -o $${LIB_NAME}_wrap.so
clean:
	rm *.o *.so test -Rf