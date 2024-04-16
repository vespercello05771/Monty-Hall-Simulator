# Monty Hall Simulator Program

## Introduction
This C++ program simulates the Monty Hall problem. In the Monty Hall problem, a contestant is presented with three doors. Behind one door is a valuable prize (e.g., a car), and behind the other two doors are less desirable prizes (e.g., goats). The contestant initially chooses one door. Then, the host (Monty Hall) reveals one of the remaining doors that does not contain the valuable prize. The contestant is then given the option to stick with their original choice or switch to the other unopened door. This program simulates multiple rounds of the game and calculates the probability of winning based on sticking with the initial choice or switching doors.

## Prerequisites
To run this program, you need to have a C++ compiler installed on your system. This program should work on any system with a standard C++ compiler and the C++11 standard library or later.

## How to Run
1. **Clone the Repository:**
    Clone this repository to your local machine using Git:
    git clone https://github.com/vespercello05771/Monty-Hall-Simulator

2. **Compile the Program:**
    Compile the C++ source code using your preferred C++ compiler. For example, using g++:
    g++ simulator.cpp -o <object_file_name>.
   
    for example : g++ simulator.cpp -o sim

4. **Run the Program:**
    Execute the compiled program:
    ./<object_file_name> <num_doors> <num_doors_opened_by_host> <num_simulations>
    
    for example: ./sim 3 1 1000

5. **View the Output:**
    The program will simulate multiple rounds of the Monty Hall problem and output the probability of winning by sticking with the initial choice and the probability of winning by switching doors.

## Customization
You can customize the program by modifying the source code (`simulator.cpp`). For example, you can enter debug mode by changing debug value to 1.

## Bonus
Mathematical Expression for Probability in Monty Hall Problem for N doors and K doors opened by host:

Given N doors the probability of choosing the door with a car is 1/N.
Hence the probability of winning the car if the player chooses to stick is 1/N, as this doesn’t change anything.

We know that the probability that the car is present is any door other than the one we chose is N-1/N. Since k doors without the car are opened by the host and the probability of the car being present in any of the remaining N-K-1 doors is 1/N-K-1, 
The probability of winning the car upon switching is the probability of not having the car on the initial choice times the probability of picking it from the N-K-1 doors which is (N-1/N)*(1/N-K-1).


