wrap: wrap.c
	gcc -fPIC -DLIB_PATH=\"$${LIB_PATH}\" --shared wrap.c -o $${LIB_NAME}_wrap.so
clean:
	rm *.o *.so test -Rf