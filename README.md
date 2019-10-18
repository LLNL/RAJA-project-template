# RAJA Project Template

This project is a template that demonstrates how to use RAJA and BLT in an
application project that uses CMake.

## Quick Start

Clone this repository, and all the submodules:

    git clone --recursive https://github.com/llnl/raja-project-template

Before we describe how to build the project, it is important to note that 
it requires out-of-source builds.

To configure and build this project using a default compiler on your system,
first create a build subdirectory in the top-level directory of this repo and 
then run CMake and make:

    mkdir build && cd build
    cmake ../
    make

This will create the binary `example.exe` in the `./bin` directory. 

When you run the executable, you will see that it runs a sequential CPU kernel.
You can also run an OpenMP multithreaded CPU kernel or a CUDA GPU kernel by 
enabling those features when you run CMake, specifically, passing the following
options to CMake:

- `-DENABLE_OPENMP=On` will enable the OpenMP back-end (RAJA default: `On`)
- `-DENABLE_CUDA=On` will enable the CUDA back-end (RAJA default: `Off`)

If you want to experiment with RAJA before trying it in your application, 
you can modify the file `./src/example.cpp`, and rebuild the code by running 
`make` in the `build` directory you created earlier.

## Using an Installed Version of RAJA

This project can also be configured to use a pre-installed version of RAJA. 
This is the recommended method for using RAJA in a large application. Please 
see the [RAJA documentation]() for details on building and installing RAJA.

Once you have RAJA installed, configure the project by specifying the RAJA
location using the CMake option `RAJA_DIR`:

    cmake -DRAJA_DIR=<path to RAJA install directory>/share/raja/cmake ../

Then build as before:

    make

If you are building your application against an installed version of RAJA,
it's important to make sure that the options you passed to CMake to build
RAJA match the options you use to build this project, apart from the one 
indicated above.

## Next Steps

- For more information on RAJA, check out the RAJA
  [tutorial](https://raja.readthedocs.io/en/master)
- For more information on using BLT and CMake, check out the BLT
  [tutorial](https://llnl-blt.readthedocs.io/en/develop)

If you have questions, comments or ideas, please join the RAJA mailing list on
Google Groups [here](https://groups.google.com/forum/#!forum/raja-users).

## License

RAJA is licensed under the BSD 3-Clause license, (BSD-3-Clause or
https://opensource.org/licenses/BSD-3-Clause).

Copyrights and patents in the RAJA project are retained by contributors.  No
copyright assignment is required to contribute to RAJA.

Unlimited Open Source - BSD 3-clause Distribution
`LLNL-CODE-689114`  `OCEC-16-063`

## SPDX usage

Individual files contain SPDX tags instead of the full license text.
This enables machine processing of license information based on the SPDX
License Identifiers that are available here: https://spdx.org/licenses/

Files that are licensed as BSD 3-Clause contain the following
text in the license header:

    SPDX-License-Identifier: (BSD-3-Clause)
