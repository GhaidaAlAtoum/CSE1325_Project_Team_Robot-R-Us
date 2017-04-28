#declare variable
CXX = g++
CXXOPTS = -std=c++11
FLTKFLAGS =  -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/freetype2 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -g -O2 -fvisibility-inlines-hidden -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT 
LDFLAGS = -Wl,-Bsymbolic-functions /usr/lib/x86_64-linux-gnu/libfltk_images.a /usr/lib/x86_64-linux-gnu/libfltk.a -lXfixes -lXext -lpthread -ldl -lm -lX11
all: sprint
sprint: USE.o Components.o Robot_part.o Model.o customer.o Sales_Associate.o shop.o Product_Manager.o PHB.o Order.o mainG.o login.o 
	$(CXX) $(CXXOPTS) $(FLTKFLAGS)$(LDFLAGS)  USE.o Robot_part.o Components.o Model.o customer.o Sales_Associate.o shop.o Product_Manager.o PHB.o Order.o mainG.o login.o  -o 'Mainnew' 'Mainnew.cpp' -Wl,-Bsymbolic-functions -lfltk_images -lfltk -lX11 
USE.o: USE.h USE.cpp
	$(CXX) -c $(CXXOPTS)  USE.cpp
Components.o: Components.h Components.cpp USE.h 
	$(CXX) -c $(CXXOPTS) Components.cpp 
Robot_part.o: Robot_part.h Robot_part.cpp USE.h 
	$(CXX) -c $(CXXOPTS)  Robot_part.cpp
Model.o: Model.h Model.cpp 
	$(CXX) -c $(CXXOPTS)  Model.cpp
customer.o: customer.h customer.cpp Order.h
	$(CXX) -c $(CXXOPTS) customer.cpp 
Sales_Associate.o: Sales_Associate.h Sales_Associate.cpp 
	$(CXX) -c $(CXXOPTS)  Sales_Associate.cpp
Product_Manager.o: Product_Manager.h Product_Manager.cpp Model.h 
	$(CXX) -c $(CXXOPTS)  Product_Manager.cpp 
PHB.o: PHB.h PHB.cpp 
	$(CXX) -c $(CXXOPTS)  PHB.cpp
Order.o: Order.h  
	$(CXX) -c $(CXXOPTS)  Order.cpp
shop.o: shop.h shop.cpp  Order.h  customer.h USE.h login.h mainG.h
	$(CXX) -c $(CXXOPTS) $(FLTKFLAGS)  shop.cpp
mainG.o: mainG.h 
	$(CXX) -c $(CXXOPTS) $(FLTKFLAGS)  mainG.cpp
login.o: login.h 
	$(CXX) -c $(CXXOPTS) $(FLTKFLAGS)  login.cpp
run:
	./sprint.out
clean: 
	rm Robot_Components_Saved.txt Robot_Models_Saved.txt -rf *o *.h.gch *.out game.out


#g++ -std=c++11 `fltk-config --cxxflags` trial.cpp  `fltk-config --ldflags` -o trial

