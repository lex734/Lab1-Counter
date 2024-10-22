verilator -Wall --cc --trace counter_challenge.sv --exe counter_challenge_tb.cpp
make -j -C obj_dir/ -f Vcounter_challenge.mk Vcounter_challenge
obj_dir/Vcounter_challenge