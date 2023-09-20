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

## Using it

Build docker image with

```
cd src
docker build -t sfincs-bmiserver .
```

To interact with it through a grpc4bmi client:

```py
from grpc4bmi.bmi_client_docker import BmiClientDocker

model = BmiClientDocker(image='sfincs-bmiserver', image_port=50051, work_dir="./")
model.get_component_name()
# 'Sfincs hydrodynamic model (C)'
```

See the example notebook shipped with this repo.

See https://grpc4bmi.readthedocs.io/en/latest/container/usage.html#docker

## Development container

To aid development, this repo is configured for use with [vscode
devcontainers](https://code.visualstudio.com/docs/devcontainers/containers). In
vscode, install the devcontainers extension, then from the command pallete
choose "Dev Containers: Open Folder in Container". This will build the container
mount your working directory, and open the remote environment in vscode. The c++
and docker extensions are automatically be loaded.
