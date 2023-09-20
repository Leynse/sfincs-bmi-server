// C++ Wrapper around sfincs-bmi fortran code
// See https://grpc4bmi.readthedocs.io/en/latest/server/Cpp.html#c-c-fortran
// See https://github.com/Deltares/SFINCS/tree/main
//
// Implemented after bmi-heat c++ example, version 2.1:
// https://github.com/csdms/bmi-example-cxx/blob/2ede037a29e34d66c274768caad1a891a70c7897/heat/bmi_heat.cxx

// SFINCS BMI implementation here:
// https://github.com/Deltares/SFINCS/blob/main/source/src/sfincs_bmi.f90
// Note: get_var not exported but it is actually implemented

#include <cstring>
#include "sfincs_bmi.hxx"

// sfincs_bmi.f90 implements/exports the following bmi functions:
extern "C" int initialize(char *c_config_file);
extern "C" int update(double dt);  // Doesn't seem to update current time
extern "C" int finalize();
extern "C" void get_start_time(double *tstart);
extern "C" void get_end_time(double *tend);
extern "C" void get_time_step(double *dt);
extern "C" void get_current_time(double *tcurrent);
// extern "C" void get_var_type(char *c_var_name, char *c_type);

// These function are also exported but not in the BMI spec
// extern "C" void get_var(char *c_var_name, real *x);  // not exported; should be get_value?
// extern "C" void set_var(char *c_var_name, float *xptr);  // should be set get_value?
// extern "C" void get_var_shape(char *c_var_name, int *var_shape);
// extern "C" void get_var_rank(char *c_var_name, int *rank);

// Model control functions.
void SfincsBmi::Initialize(std::string config_file) {
  // Convert c-string to character array
  const int length = config_file.length();
  char* c_config_file = new char[length + 1];
  strcpy(c_config_file, config_file.c_str());
  initialize(c_config_file);
  delete[] c_config_file;
}
void SfincsBmi::Update() {
  double dt = this->GetTimeStep();
  // dt = 1.;  // The initial time step is super small (1e-6)
  int status = update(dt);
  if (status != 0) {
    throw BmiError();
  }
}
void SfincsBmi::UpdateUntil(double time) {
  double t = this->GetCurrentTime();
  while (t < time) {
    this->Update();
    t = this->GetCurrentTime();
  };
}
void SfincsBmi::Finalize() {
  int status = finalize();
  if (status != 0) {
    throw BmiError();
  }
}

// Model information functions.
std::string SfincsBmi::GetComponentName() {
  return "Sfincs hydrodynamic model (C)";
}
int SfincsBmi::GetInputItemCount() {
  // TODO: implement
  throw NotImplemented();
}
int SfincsBmi::GetOutputItemCount() {
  // TODO: implement
  throw NotImplemented();
}
std::vector<std::string> SfincsBmi::GetInputVarNames() {
  // TODO: implement
  throw NotImplemented();
}
std::vector<std::string> SfincsBmi::GetOutputVarNames() {
  // TODO: implement
  throw NotImplemented();
}

// Variable information functions
int SfincsBmi::GetVarGrid(std::string name) {
  // TODO: implement
  throw NotImplemented();
}
std::string SfincsBmi::GetVarType(std::string name) {
  // TODO: implement
  throw NotImplemented();
}
std::string SfincsBmi::GetVarUnits(std::string name) {
  // TODO: implement
  throw NotImplemented();
}
int SfincsBmi::GetVarItemsize(std::string name) {
  // TODO: implement
  throw NotImplemented();
}
int SfincsBmi::GetVarNbytes(std::string name) {
  // TODO: implement
  throw NotImplemented();
}
std::string SfincsBmi::GetVarLocation(std::string name) {
  // TODO: implement
  throw NotImplemented();
}

double SfincsBmi::GetCurrentTime() {
  double t;
  get_current_time(&t);
  return t;
}
double SfincsBmi::GetStartTime() {
  double starttime;
  get_start_time(&starttime);
  return starttime;
}
double SfincsBmi::GetEndTime() {
  double endtime;
  get_end_time(&endtime);
  return endtime;
}
std::string SfincsBmi::GetTimeUnits() {
  // TODO: implement
  throw NotImplemented();
}
double SfincsBmi::GetTimeStep() {
  double dt;
  get_time_step(&dt);
  return dt;
}

// Variable getters
void SfincsBmi::GetValue(std::string name, void *dest) {
  // TODO: implement
  throw NotImplemented();
}
void *SfincsBmi::GetValuePtr(std::string name) {
  // TODO: implement
  throw NotImplemented();
}
void SfincsBmi::GetValueAtIndices(std::string name, void *dest, int *inds,
                                  int count) {
  // TODO: implement
  throw NotImplemented();
}

// Variable setters
void SfincsBmi::SetValue(std::string name, void *src) {
  // TODO: implement
  throw NotImplemented();
}
void SfincsBmi::SetValueAtIndices(std::string name, int *inds, int count,
                                  void *src) {
  // TODO: implement
  throw NotImplemented();
}

// Grid information functions
int SfincsBmi::GetGridRank(const int grid) {
  // TODO: implement
  throw NotImplemented();
}
int SfincsBmi::GetGridSize(const int grid) {
  // TODO: implement
  throw NotImplemented();
}
std::string SfincsBmi::GetGridType(const int grid) {
  // TODO: implement
  throw NotImplemented();
}

void SfincsBmi::GetGridShape(const int grid, int *shape) {
  // TODO: implement
  throw NotImplemented();
}
void SfincsBmi::GetGridSpacing(const int grid, double *spacing) {
  // TODO: implement
  throw NotImplemented();
}
void SfincsBmi::GetGridOrigin(const int grid, double *origin) {
  // TODO: implement
  throw NotImplemented();
}

void SfincsBmi::GetGridX(const int grid, double *x) {
  // TODO: implement
  throw NotImplemented();
}
void SfincsBmi::GetGridY(const int grid, double *y) {
  // TODO: implement
  throw NotImplemented();
}
void SfincsBmi::GetGridZ(const int grid, double *z) {
  // TODO: implement
  throw NotImplemented();
}

int SfincsBmi::GetGridNodeCount(const int grid) {
  // TODO: implement
  throw NotImplemented();
}
int SfincsBmi::GetGridEdgeCount(const int grid) {
  // TODO: implement
  throw NotImplemented();
}
int SfincsBmi::GetGridFaceCount(const int grid) {
  // TODO: implement
  throw NotImplemented();
}

void SfincsBmi::GetGridEdgeNodes(const int grid, int *edge_nodes) {
  // TODO: implement
  throw NotImplemented();
}
void SfincsBmi::GetGridFaceEdges(const int grid, int *face_edges) {
  // TODO: implement
  throw NotImplemented();
}
void SfincsBmi::GetGridFaceNodes(const int grid, int *face_nodes) {
  // TODO: implement
  throw NotImplemented();
}
void SfincsBmi::GetGridNodesPerFace(const int grid, int *nodes_per_face) {
  // TODO: implement
  throw NotImplemented();
}
