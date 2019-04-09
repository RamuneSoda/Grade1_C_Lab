cc = gcc
prom = Lab4
deps = Lab4_fun.h Lab4_run.h Lab4_data.h
obj = Lab4.o Lab4_fun.o Lab4_run.o

$(prom): $(obj)
	$(cc) -o $(prom) $(obj)

%.o: %.c $(deps)
	$(cc) -c $< -o $@
clean:
	rm -f *.o