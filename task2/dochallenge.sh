#!/bin/sh

# cleanup
rm -rf obj_dir
rm -f counter.vcd

source ./attach_usb.sh
# run Verilator to translate Verilog into C++, including C++ testbench
verilator -Wall --cc --trace counter_challenge.sv --exe counter_challenge_tb.cpp

# build C++ project via make automatically geenerated by Verilator
make -j -C obj_dir/ -f Vcounter_challenge.mk Vcounter_challenge

# run executable simulation file
obj_dir/Vcounter_challenge