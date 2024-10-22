# Task 2
Connect Vbuddy using vbuddy.cpp and vbuddy.cfg
Using /tools/attach_usb.sh, I was able to identify the name of my port as /dev/ttyUSB0

Then, I was able to produce the counter and reflect that in the TFT of the Vbuddy.
Next, I was also able to insert vbdflag() to ensure the switch becomes the EN flag to enable and disable the counter.

To produce another interface and show the counter as a plot instead of hexadecimals, I increased the number of cycles from 300 to 600. Upon recompiling, I was able to get an increasing straight line graph which upon pressing the button, becomes horizontal, then it straightens.

# Challenge
Change the inputs of EN such that the count decreases when the EN == 0 and count increases when EN == 1.