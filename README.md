# gr-shared_memory

This test project aims to transmit data between two flow graphs without using sockets or pipes, but instead using boost shared memory.   
At the end there should be three blocks: 
* Sample Counter 
* Shared Memory Writer
* Shared Memory Reader

My aim is it to be able to use data from gnuradio in other programs without integrating gnuradio. 

## Sample Counter

This block simply is for testing.  
It will print the Samples per second into the console. 

## Shared Memory Writer 

Writes an amount of samples into a shared memory region and will notify any reader listening.  
Work in progress.

## Shared Memory Reader

Reads any shared memory specified.  
Not started yet.

# Installing 

As this out of tree module has been built with gr_modtool, installing it is simple:  
```bash
mkdir build 
cd build
cmake ..
make && sudo make install && sudo ldconfig
```
