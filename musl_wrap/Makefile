test: test.c musl_wrapper.so
	gcc test.c -lm -o test
musl_wrapper.so: musl_wrapper.c
	gcc -fPIC --shared musl_wrapper.c -o musl_wrapper.so
clean:
	rm *.o *.so test -Rf