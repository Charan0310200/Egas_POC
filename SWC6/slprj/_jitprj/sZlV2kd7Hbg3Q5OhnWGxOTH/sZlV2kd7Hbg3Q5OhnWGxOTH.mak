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
	   sZlV2kd7Hbg3Q5OhnWGxOTH.o \
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
     -I"F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\sZlV2kd7Hbg3Q5OhnWGxOTH" \
     -I"F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6" \

#--------------------------------- Rules --------------------------------------

sZlV2kd7Hbg3Q5OhnWGxOTH.dll : $(MAKEFILE) $(OBJECTS)
	$(LD) $(LDFLAGS) -o sZlV2kd7Hbg3Q5OhnWGxOTH.dll $(OBJECTS) -Wl,--whole-archive $(STATICLIBS)  "-llibmex" "-llibmx" -Wl,-no-whole-archive
sZlV2kd7Hbg3Q5OhnWGxOTH.o :	F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\sZlV2kd7Hbg3Q5OhnWGxOTH\sZlV2kd7Hbg3Q5OhnWGxOTH.c
	$(CC) $(CFLAGS) -fvisibility=hidden $(INCLUDE_PATH) "F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\sZlV2kd7Hbg3Q5OhnWGxOTH\sZlV2kd7Hbg3Q5OhnWGxOTH.c"
half_type.o :	F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\sZlV2kd7Hbg3Q5OhnWGxOTH\half_type.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\sZlV2kd7Hbg3Q5OhnWGxOTH\half_type.c"
