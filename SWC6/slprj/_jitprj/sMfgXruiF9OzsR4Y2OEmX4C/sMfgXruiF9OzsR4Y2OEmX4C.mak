#------------------------ Tool Specifications & Options ----------------------

COMPILER  =  mingw64

CC        =  "gcc"
LD        =  "gcc"
LIBCMD    =  "gcc"
CFLAGS    =  -c -m64 -O2 -DNDEBUG -DMATLAB_MEX_FILE
LDFLAGS   =  -m64 -shared -static -s -Wl,--no-undefined -L"F:\Matlab_2025B\extern\lib\win64\mingw64"

CXX        =  "g++"
LDXX       =  "g++"
CXXFLAGS   =  -c -m64 -O2 -DNDEBUG -DMATLAB_MEX_FILE -std=c++14

OBJECTS = \
	   sMfgXruiF9OzsR4Y2OEmX4C.o \
	   half_type.o \

STATICLIBS = \
	   "-lsf_runtime" \
	   "-llibcovrt" \
	   "-llibemlrt" \
	   "-llibmwblas" \
	   "-llibmwcgxert" \
	   "-llibmwlapack" \
	   "-llibmwmathutil" \
	   "-llibmwsl_sfcn_cov_bridge" \
	   "-llibmwslexec_simlog" \
	   "-llibmwstringutil" \
	   "-llibut" \

#------------------------------ Include/Lib Path ------------------------------

INCLUDE_PATH = \
     -I"F:\Matlab_2025B\extern\include" \
     -I"F:\Matlab_2025B\simulink\include" \
     -I"F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\sMfgXruiF9OzsR4Y2OEmX4C" \
     -I"F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6" \

#--------------------------------- Rules --------------------------------------

sMfgXruiF9OzsR4Y2OEmX4C.dll : $(MAKEFILE) $(OBJECTS)
	$(LD) $(LDFLAGS) -o sMfgXruiF9OzsR4Y2OEmX4C.dll $(OBJECTS) -Wl,--whole-archive $(STATICLIBS)  "-llibmex" "-llibmx" -Wl,-no-whole-archive
sMfgXruiF9OzsR4Y2OEmX4C.o :	F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\sMfgXruiF9OzsR4Y2OEmX4C\sMfgXruiF9OzsR4Y2OEmX4C.c
	$(CC) $(CFLAGS) -fvisibility=hidden $(INCLUDE_PATH) "F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\sMfgXruiF9OzsR4Y2OEmX4C\sMfgXruiF9OzsR4Y2OEmX4C.c"
half_type.o :	F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\sMfgXruiF9OzsR4Y2OEmX4C\half_type.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\sMfgXruiF9OzsR4Y2OEmX4C\half_type.c"
