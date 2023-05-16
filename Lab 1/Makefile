plot: HaKaPr_plot.py t_a.txt t_b.txt t_c.txt t_d.txt HaKaPr_x.txt
	python3 HaKaPr_plot.py

HaKaPr_task4_boost.so: HaKaPr_task4_boost.cpp
	g++ -Wall -Wextra -fPIC -shared HaKaPr_task4_boost.cpp -o HaKaPr_task4_boost.so -I /usr/include/python3.10/ -lboost_python310 -lpython3.10 -lboost_numpy310 

task1: HaKaPr_task1.cpp HaKaPr_input.txt	
	g++ HaKaPr_task1.cpp && ./a.out

task2: HaKaPr_task2.py HaKaPr_input.txt
	python3 HaKaPr_task2.py

task3: HaKaPr_task3.py HaKaPr_input.txt
	python3 HaKaPr_task3.py

task4: HaKaPr_task4.py HaKaPr_task4_boost.so HaKaPr_input.txt
	python3 HaKaPr_task4.py
	
t_a.txt:
	make task1

t_b.txt:
	make task2

t_c.txt:
	make task3

t_d.txt:
	make task4
	
clean:
	rm *.so *.out t_a.txt t_b.txt t_c.txt t_d.txt	#don't delete input.txt or x.txt
