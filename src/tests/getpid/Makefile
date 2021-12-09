always:

p1: always
	g++ -g -std=c++14 -I$(XILINX_XRT)/include -L$(XILINX_XRT)/lib -o p1 p1.cpp -lxrt_coreutil -pthread

p2: always
	g++ -g -std=c++14 -I$(XILINX_XRT)/include -L$(XILINX_XRT)/lib -o p2 p2.cpp -lxrt_coreutil -pthread

p1_bo: always
	g++ -g -std=c++14 -I$(XILINX_XRT)/include -L$(XILINX_XRT)/lib -o p1_bo p1_bo.cpp -lxrt_coreutil -pthread

p2_bo: always
	g++ -g -std=c++14 -I$(XILINX_XRT)/include -L$(XILINX_XRT)/lib -o p2_bo p2_bo.cpp -lxrt_coreutil -pthread

p2_xbo: always
	g++ -g -std=c++14 -I$(XILINX_XRT)/include -L$(XILINX_XRT)/lib -o p2_xbo p2_xbo.cpp -lxrt_coreutil -pthread
