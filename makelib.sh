bash extracth.sh
gcc -c src/*.cpp && ar rcs lib/libHiCPPM.a *.o && rm *.o