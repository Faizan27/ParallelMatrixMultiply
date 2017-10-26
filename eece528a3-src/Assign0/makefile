compiler=gcc
Xtraflag = -ftree-vectorize -m64 -march=broadwell -mtune=intel
loopunrol = -funroll-loops
all: compiling simple transforms

clean:
	rm -rf *.o *.exe

clean_all: clean
	rm -rf *.s *.csv

.PHONY: all clean clean_all

simple:
	$(compiler) assign0_int.c -o assign0_int_none.exe 
	$(compiler) -O assign0_int.c -o assign0_int_O.exe
	$(compiler) -O1 assign0_int.c -o assign0_int_O1.exe
	$(compiler) -O2 assign0_int.c -o assign0_int_O2.exe
	$(compiler) -O3 assign0_int.c -o assign0_int_O3.exe
	$(compiler) -O2 $(Xtraflag) assign0_int.c -o assign0_int_O2Xtra.exe

	$(compiler) assign0_float.c -o assign0_float_none.exe
	$(compiler) -O assign0_float.c -o assign0_float_O.exe
	$(compiler) -O1 assign0_float.c -o assign0_float_O1.exe
	$(compiler) -O2 assign0_float.c -o assign0_float_O2.exe
	$(compiler) -O3 assign0_float.c -o assign0_float_O3.exe
	$(compiler) -O2 $(Xtraflag) assign0_float.c -o assign0_float_O2Xtra.exe

	$(compiler) assign0_double.c -o assign0_double_none.exe
	$(compiler) -O assign0_double.c -o assign0_double_O.exe
	$(compiler) -O1 assign0_double.c -o assign0_double_O1.exe
	$(compiler) -O2 assign0_double.c -o assign0_double_O2.exe
	$(compiler) -O3 assign0_double.c -o assign0_double_O3.exe
	$(compiler) -O2 $(Xtraflag) assign0_double.c -o assign0_double_O2Xtra.exe

compiling:
	echo "Compiling the programs"


transforms:

	$(compiler) $(loopunroll) assign0_int_Transform.c -o assign0_int_none_Transform.exe
	$(compiler) -O $(loopunroll) assign0_int_Transform.c -o assign0_int_O_Transform.exe
	$(compiler) -O1 $(loopunroll) assign0_int_Transform.c -o assign0_int_O1_Transform.exe
	$(compiler) -O2 $(loopunroll) assign0_int_Transform.c -o assign0_int_O2_Transform.exe
	$(compiler) -O3 $(loopunroll) assign0_int_Transform.c -o assign0_int_O3_Transform.exe
	$(compiler) -O2 $(Xtraflag) $(loopunroll) assign0_int_Transform.c -o assign0_int_O2Xtra_Transform.exe

	$(compiler) $(loopunroll) assign0_float_Transform.c -o assign0_float_none_Transform.exe
	$(compiler) -O $(loopunroll) assign0_float_Transform.c -o assign0_float_O_Transform.exe
	$(compiler) -O1 $(loopunroll) assign0_float_Transform.c -o assign0_float_O1_Transform.exe
	$(compiler) -O2 $(loopunroll) assign0_float_Transform.c -o assign0_float_O2_Transform.exe
	$(compiler) -O3 $(loopunroll) assign0_float_Transform.c -o assign0_float_O3_Transform.exe
	$(compiler) -O2 $(Xtraflag) $(loopunroll) assign0_float_Transform.c -o assign0_float_O2Xtra_Transform.exe

	$(compiler) $(loopunroll) assign0_double_Transform.c -o assign0_double_none_Transform.exe
	$(compiler) -O $(loopunroll) assign0_double_Transform.c -o assign0_double_O_Transform.exe
	$(compiler) -O1 $(loopunroll) assign0_double_Transform.c -o assign0_double_O1_Transform.exe
	$(compiler) -O2 $(loopunroll) assign0_double_Transform.c -o assign0_double_O2_Transform.exe
	$(compiler) -O3 $(loopunroll) assign0_double_Transform.c -o assign0_double_O3_Transform.exe
	$(compiler) -O2 $(Xtraflag) $(loopunroll) assign0_double_Transform.c -o assign0_double_O2Xtra_Transform.exe
