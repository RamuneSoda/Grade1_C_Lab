cc = gcc
prom = Lab3
deps = Lab3_fun.h Lab3_run.h Lab3_data.h
obj = Lab3.o Lab3_fun.o Lab3_run.o

$(prom): $(obj)
	$(cc) -o $(prom) $(obj)

%.o: %.c $(deps)
	$(cc) -c $< -o $@
clean:
	rm -f *.o