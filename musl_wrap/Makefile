test: test.c musl_wrap.so
	gcc test.c -lm -o test
musl_wrap.so: musl_wrap.c
	gcc -fPIC --shared musl_wrap.c -o musl_wrap.so
clean:
	rm *.o *.so test -Rf