# TGA Performance Challenge - 2017

##### Overview
You will be required to implement a solution to determine if a file contains duplicates of registration numbers.

* The file is guaranteed to exist, and contains one registration number per line
* The format of the registration numbers is 'AAA999'
* Sample data is in the range of 64k to 32Mb, expect to be evaluated against large file sizes
* The goal is to determine the presence of duplicates as quickly as possible

#### Input parameters
Your implementation will receive a const std::string& filename as input.

#### Return value
Your implementation will return a bool, indicating if the file contained duplicates

#### Setup
In order to complete setup for this repository
* Clone or download this repository (https://github.com/johron/perf-challenge)
* In the perf-challenge-app/src/participants folder, duplicate the 'reference_user' folder and rename it to 'firstname_lastname' (using your own name).
* open the files 'Implementation.h/.cpp' and rename the namespace from 'reference_user' to 'firstname_lastname' like above. These have to match.
* Ensure you have CMake 3.1 or later installed
* In the project directory run the following CMake command in order to generate the solution. Solution files are generated in the .build folder

 ´´´
 cmake . -B.build
 ´´´


### Remember
* Set your working directory to the perf-challenge-app folder (where the data folder can be found)
