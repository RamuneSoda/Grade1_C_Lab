cc = gcc
deps = Lab5_call.h Lab5_conf.h Lab5_data.h Lab5_loadfile.h Lab5_main.h Lab5_init.h
dc = Lab5.c Lab5_main.c Lab5_init.c Lab5_call.c Lab5_conf.c Lab5_loadfile.c Lab5_view.c

Lab5: $(dc) $(deps)
	$(cc) $(dc) -o Lab5
clean:
	rm -f *.o
love:
	$(cc) $(dc) -o Lab5 -g
4:
	gcc -o Lab4 Lab4.c Lab4_fun.c Lab4_run.c