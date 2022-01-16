# Zephyr_Multithread
## 1. Environment setup
### a. For windows operating systems
* download [virtual box](https://www.virtualbox.org/wiki/Downloads).
* Install [ubuntu](https://ubuntu.com/#download) as a virtual machine.
* follow [this tutorial](https://www.youtube.com/watch?v=x5MhydijWmc) for setting up ubuntu virtual machine on windows 
* Follow [Zephyr documentation](https://docs.zephyrproject.org/latest/getting_started/index.html) to setup build environment.
### b. For linux operating systems
* Follow [Zephyr documentation](https://docs.zephyrproject.org/latest/getting_started/index.html) to setup build environment.

## 2. Clone the project
* Clone the Zephyr_Multithread project to [home directory]/zephyrproject/zephyr/samples/basic/

## 3. Running the project
* Open terminal 
* Navigate to `cd ~/zephyrproject/zephyr`
* run the command `west build -p auto -b native_posix samples/basic/Zephyr_Multithread`
* run the command `west build -t run`

## 4. Project Information
* This project runs 2 threads.
* Thread 1 prints `Thread 1` repeatedly.
* The time period of printing increases by 1 seconds at each iteration
* When the time period reaches 10 seconds, the time period resets itself
* Thread 1 also passes a message to fifo buffer after its execution.
* Thread ideally waits for the message from thread 1.
* If thread 2 receives message from thread 1, it prints `Thread 2`
