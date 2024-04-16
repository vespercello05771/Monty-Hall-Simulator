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
    g++ simulator.cpp -o <object_file_name>
    for example : g++ simulator.cpp -o sim

3. **Run the Program:**
    Execute the compiled program:
    ./<object_file_name> <num_doors> <num_doors_opened_by_host> <num_simulations>
    for example: ./sim 3 1 1000

4. **View the Output:**
    The program will simulate multiple rounds of the Monty Hall problem and output the probability of winning by sticking with the initial choice and the probability of winning by switching doors.

## Customization
You can customize the program by modifying the source code (`simulator.cpp`). For example, you can enter debug mode by changing debug value to 1.


