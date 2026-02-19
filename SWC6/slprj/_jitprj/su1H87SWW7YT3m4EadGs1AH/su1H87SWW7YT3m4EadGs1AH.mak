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
	   su1H87SWW7YT3m4EadGs1AH.o \
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
     -I"F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\su1H87SWW7YT3m4EadGs1AH" \
     -I"F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6" \

#--------------------------------- Rules --------------------------------------

su1H87SWW7YT3m4EadGs1AH.dll : $(MAKEFILE) $(OBJECTS)
	$(LD) $(LDFLAGS) -o su1H87SWW7YT3m4EadGs1AH.dll $(OBJECTS) -Wl,--whole-archive $(STATICLIBS)  "-llibmex" "-llibmx" -Wl,-no-whole-archive
su1H87SWW7YT3m4EadGs1AH.o :	F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\su1H87SWW7YT3m4EadGs1AH\su1H87SWW7YT3m4EadGs1AH.c
	$(CC) $(CFLAGS) -fvisibility=hidden $(INCLUDE_PATH) "F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\su1H87SWW7YT3m4EadGs1AH\su1H87SWW7YT3m4EadGs1AH.c"
half_type.o :	F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\su1H87SWW7YT3m4EadGs1AH\half_type.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "F:\POC\EGas_Models\Git_Clone\Egas_POC\SWC6\slprj\_jitprj\su1H87SWW7YT3m4EadGs1AH\half_type.c"
