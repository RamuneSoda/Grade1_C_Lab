cc = gcc
deps = Lab6_call.h Lab6_conf.h Lab6_data.h Lab6_loadfile.h Lab6_main.h Lab6_init.h Lab6_sort.h
dc = Lab6.c Lab6_main.c Lab6_init.c Lab6_call.c Lab6_conf.c Lab6_loadfile.c Lab6_view.c Lab6_sort.c

Lab6: $(dc) $(deps)
	$(cc) $(dc) -o Lab6
clean:
	rm -f *.o
love:
	$(cc) $(dc) -o Lab6 -g