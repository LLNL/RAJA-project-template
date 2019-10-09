# RAJA Project Template

This project is a template that demonstrates how to use RAJA and BLT in a CMake
project.

## Quick Start

Clone this repository, and all the submodules:

    git clone --recursive https://github.com/llnl/raja-project-template

Configure using CMake:

    mkdir build && cd build
    cmake ../

Note that this project requires out-of-source builds. Finally, you can build
the project:

    make

This will create the binary `example.exe` in the `./bin` directory.

The following options can be passed to CMake to enable additional RAJA backends:

- `ENABLE_OPENMP` will enable the OpenMP backend (default: `On`)
- `ENABLE_CUDA` will enable the CUDA backend (default: `Off`)

To experiment with writing your own RAJA application, you can modify the file
`./src/example.cpp`, and rebuild the code by running `make` in the `build`
directory you created earlier.

## Next Steps

- For more information on RAJA, check out the RAJA
  [tutorial](https://raja.readthedocs.io/en/master)
- For more information on using BLT and CMake, check out the BLT
  [tutorial](https://llnl-blt.readthedocs.io/en/develop)

If you have qeustions, comments or ideas, please join the RAJA mailing list on
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
