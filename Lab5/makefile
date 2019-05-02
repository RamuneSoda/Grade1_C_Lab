cc = gcc
deps_1 = Lab4_fun.h Lab4_run.h Lab4_data.h
obj_1 = Lab4.o Lab4_fun.o Lab4_run.o
deps_2 = Lab5_fun.h Lab5_run.h
obj_2 = Lab5.o Lab5_fun.o Lab5_run.o

Lab4: $(obj_1)
	$(cc) -o Lab4 $(obj_1)
%.o: %.c $(deps_1)
	$(cc) -c $< -o $@
clean:
	rm -f *.o