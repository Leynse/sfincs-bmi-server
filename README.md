# sfincs-bmi-server

grpc4bmi wrapper around Delteras/sfincs BMI for use with eWaterCycle.

* See https://github.com/Deltares/SFINCS/tree/main
* See https://grpc4bmi.readthedocs.io/en/latest/server/Cpp.html#c-c-fortran

To interop with grpc, a c++ wrapper is added on top of the fortran code. So we have:

sfincs_bmi.f90 --> sfincs_bmi.cxx --> sfincs_bmi_server.cxx

The c++ wrapper is modelled after [bmi-heat c++ example, version
2.1](https://github.com/csdms/bmi-example-cxx/blob/2ede037a29e34d66c274768caad1a891a70c7897/heat/bmi_heat.hxx).

For an example see https://github.com/eWaterCycle/hype-bmi/. Note that this uses
an older version of the BMI spec.


## Development container

To aid development, this package is configured for use with [vscode
devcontainers](https://code.visualstudio.com/docs/devcontainers/containers). In
vscode, install the devcontainers extension, then from the command pallete
choose "Dev Containers: Open Folder in Container". This will build the container
mount your working directory, and open the remote environment in vscode. The c++
and docker extensions are automatically be loaded.
