# SlideCapture-App
An app for video lectures, etc. that captures and saves different displayed slides of a displayed presentation 
This is a simple C++ project built using CMake.
Follow the steps below to download, build, and run it on your computer.
Requirements
Before you start, make sure you have:
C++ compiler (g++ / clang / MSVC)
CMake installed

How to Build and Run
1. Download the project

Open your terminal (or PowerShell on Windows) and run:

git clone https://github.com/Llamahahaha/SlideCapture-App.git
cd SlideCapture-App.git

2. Create a build folder

This keeps compiled files separate from your source code:

mkdir build
cd build

3. Generate build files with CMake and build(compile) the project

Run:

cmake ..

    The .. tells CMake to look at the CMakeLists.txt file in the parent folder.

    CMake will check your system and prepare the project for building.
    This compiles the program into an executable file.

cmake --build .

    On Windows, it will create a .exe file inside Debug or Release folders.

    On Linux/macOS, it will create an executable with no extension.
    
Or if you have ninja:
cmake -G Ninja ..
ninja

4. Run the program

On Linux / macOS:

./MyProgram

On Windows (PowerShell or CMD):

.\Debug\MyProgram.exe

(Replace MyProgram with the name given in CMakeLists.txt if it’s different.)
Cleaning Up

If you ever want to start fresh:

cd ..
rm -rf build

Then repeat steps 2–5.
