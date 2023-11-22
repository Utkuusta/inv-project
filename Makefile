all: main.cpp
	$(CXX) $(CXXFLAGS) -Og main.cpp wpa_wifi.cpp -g -o hello.bin 
clean: 
	rm -f hello.bin