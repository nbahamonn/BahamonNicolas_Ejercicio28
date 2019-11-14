friccion.png : rk4.py rk4.dat Pro.dat 
	python rk4.py
    
rk4.dat Pro.dat : rk4.x
	./rk4.x

rk4.x : rk4.cpp
	c++ rk4.cpp -o rk4.x
    
clean: 
	rm friccion.png rk4.dat
    