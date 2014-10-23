// Author: Mingcheng Chen (linyufly@gmail.com)

#ifndef FLOW_MAP_CONVERTER_H_
#define FLOW_MAP_CONVERTER_H_

class vtkStructuredPoints;

class FlowMapConverter {
 public:
  void set_origin(double x, double y, double z) {
    dimensions_[0] = x;
    dimensions_[1] = y;
    dimensions_[2] = z;
  }

  void set_spacing(double dx, double dy, double dz) {
    spacing_[0] = dx;
    spacing_[1] = dy;
    spacing_[2] = dz;
  }

  void set_dimensions(int nx, int ny, int nz) {
    dimensions_[0] = nx;
    dimensions_[1] = ny;
    dimensions_[2] = nz;
  }

  vtkStructuredPoints *read_flow_map(const char *file_name);

 private:
  double origin_[3];
  double spacing_[3];
  int dimensions_[3];
};

#endif  // FLOW_MAP_CONVERTER_H_
