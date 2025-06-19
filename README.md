# ips-DEV

## 1. Installation

**WARNING :** the repertory `include` contains from-sources built libraries required for the project to run ('Armadillo' and also 'OpenBLAS' which is needed by 'Armadillo' itself). Those libraires have been compiled locally for this project specifically, and are pushed on this depository **only for demonstration purposes**. OpenBLAS requires to identify your CPU during its compilation, which ultimately will result in **a different build from the one on this depository !!**\
Make sure to follow the instructions below to generated libs adapted to your hardware.

### OpenBLAS

Clone OpenBLAS project from this url : `https://github.com/OpenMathLib/OpenBLAS` and follow the instructions.\
Basically, when you are in the OpenBLAS's newly cloned repository, commands to enter in your shell should be :
* `make`
* `make PREFIX=your/path/to/ips-DEV/include/OpenBLAS-lib` install

### Armadillo
