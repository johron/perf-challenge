# King Performance Challenge - 2019

##### Overview
The challenge is to implement a solution to determine if a file contains duplicates of registration numbers.

* The file is guaranteed to exist, and contains one registration number per line
* The format of the registration numbers is 'AAA999'
* Sample data is in the range of 64k to 32Mb, expect to be evaluated against large file sizes
* The goal is to determine the presence of duplicates as quickly as possible

--------------

#### Input parameters
Your implementation will receive a `const std::string&` filename as input.

--------------

#### Return value
Your implementation will return a `bool`, indicating if the file contained duplicates

--------------

#### Setup
In order to complete setup for this repository
* Clone or download this repository (https://github.com/johron/perf-challenge)
* In the perf-challenge-app/src/participants folder, duplicate the `reference_user` folder and rename it to `firstname_lastname` (using your own name).
* open the files `Implementation.h/.cpp` and rename the namespace from `reference_user` to `firstname_lastname` like above. These have to match.
* In `Implementation.h` change `GetName()` to return your name (lowercase for consistency please)
* Ensure you have CMake 3.1 or later installed
* Run the following command in the project folder to generate the solution files
* Windows: `c:\dev\perf-challenge> cmake . -B_build`
* Mac: `./generate_xcode_project.sh` 
* Open the solution/project file that was generated in the _build folder.
* Set `perf-challenge-app` to the startup project / active scheme
* Mac: Product->Scheme->Edit Scheme->Options: Set Working Directory: $(BUILD_DIR)
* Run your program in **Release** the first time to generate the test files.
* If everything has been setup correctly, you should be able to run the code and see the reference user attempt to solve the problem... with questionable efficiency.
* Open `perf-challenge-app/Source/Participants/firstname_lastname/Implementation.cpp` and get started. Happy optimizing!

--------------

#### Failing criteria
* Your implementation does not compile
* Your implementation crashes runtime
* Your implementation does not correctly identify existance of duplicates

--------------

#### Questions & Answers
 *Q: Will timing include reading from disk?*
> A: Yes

 *Q: Can we assume that each line in the files have a certain format?*
 > Yes, three characters (A-Z) and 3 numbers (0-9). Windows line endings. There will be no invalid data entries or bad formatting.

 *Q: What build configuration will be used?*
 > We will build using Visual Studio 2017. The Release configuration will be used, as generated by the provided cmake config.
