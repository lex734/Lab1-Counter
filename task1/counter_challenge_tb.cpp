#include "Vcounter_challenge.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv, char **env)
{
    int i;
    int clk;
    int pause = 3;

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vcounter_challenge *top = new Vcounter_challenge;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("counter_challenge.vcd");

    // initialise simulation inputs
    top->clk = 1;
    top->rst = 1;
    top->en = 0;
    top->count;

    // run simulation for many clock cycles
    for (i = 0; i < 300; i++)
    {
        if (top->count == 0x9 && pause > 0)
        {
            pause -= 1;
            top->en = 0;
        }
        else if (top->count == 0x9 && pause == 0)
        {
            pause = 3;
            top->en = 1;
        }
        // dump variables into VCD file and toggle clock
        for (clk = 0; clk < 2; clk++)
        {
            tfp->dump(2 * i + clk);
            top->clk = !top->clk;
            top->eval();
        }
        top->rst = (i < 2) | (i == 15);
        top->en = (i > 4);
        if (Verilated::gotFinish())
            exit(0);
    }
    tfp->close();
    exit(0);
}