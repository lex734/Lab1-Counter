# Initialising the counter
## Trace as seen from gtkwave
![](image.png)

Since WIDTH is specified to be 8, this is an 8 bit binary counter.
On the rising edge of the clock, if reset is 0 and EN is 1, then the counter increases by 1 bit. When it reaches 1111111, then it resets back to 00000000.

## Syntax to take note off
- width is set to 8 bits using parameter WIDTH
- always_ff @ (posedge clk) is the way to specify a clocked circuit
- <= are no-bllock assignments used within an always_ff block. it means GET
- {WIDTH{1'b0}} uses concaternation operator to form WIDTH bits of '0'

In line 13 of the code, 
```count <= count + {{WIDTH-1{1'b0}}, en}``` which means that 7 bits of 0 are concatenated with en which is the LSB. This is added to 8 bit count. Hence, this is simple 8 bit output.