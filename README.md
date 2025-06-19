# ips-DEV

## 1. Installation

**WARNING :** the repertory `include` contains from-sources built libraries required for the project to run ('Armadillo' and also 'OpenBLAS' which is needed by 'Armadillo' itself). Those libraires have been compiled locally for this project specifically, and are pushed on this depository **only for demonstration purposes**. OpenBLAS requires to identify your CPU during its compilation, which ultimately will result in **a different build from the one on this depository !!**\
Make sure to follow the instructions below to generated libs adapted to your hardware.

### OpenBLAS

Clone OpenBLAS project from this url : `https://github.com/OpenMathLib/OpenBLAS` and follow the instructions.\
Basically, when you are in OpenBLAS's newly cloned repository, commands to enter in your shell should be :
* `make`
* `make PREFIX=/your/path/to/ips-DEV/include/OpenBLAS-lib install`

### Armadillo

Clone Armadillo project from this url : `https://gitlab.com/conradsnicta/armadillo-code`.\
Basically, when you are in armadillo's newly cloned repository,  commands to enter in your shell should be :
* `cmake . -DCMAKE_INSTALL_PREFIX:PATH=/your/path/to/ips-DEV/include/armadillo-lib`
* `make install`

Be careful that if you've installed OpenBLAS in a local/not standard folder, the cmake command may not find the location of the OpenBLAS' library. They must be a way to specify to camke its correct path but hey, I don't do cmake so I don't know how to do so.\
What you can do is to make an export of your `PATH` environment variable to add the location of the OpenBLAS's library (in our case, in `/your/path/to/ips-DEV/include/OpenBLAS-lib/lib`).

## Other dependencies
