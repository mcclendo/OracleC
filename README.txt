Name: Charles McClendon
CS username: mcclendo

This project uses cmake to build its files. The quickest way to build and test the proect is to perform these commands from the project root.

mkdir build
cd build
cmake ../src
cmake --build .
./proj1 input.txt


The build directory can be anywhere you would like; this is only an example. Note that 'build/' is ignored by git. The second cmake command actually performs the build/compilation step. There is included a sample input file. When the program is run, it reads the input file and outputs the desired report.

This version of the program supports more than 1 order but assumes the input is well-formed, though there is very limited error checking (such as if an unknown "wood type" is inserted).
