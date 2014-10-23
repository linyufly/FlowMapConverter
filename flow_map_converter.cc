// Author: Mingcheng Chen (linyufly@gmail.com)

#include "flow_map_converter.h"

#include <vtkStructuredPoints.h>

#include <cstdio>
#include <cstdlib>

vtkStructuredPoints *FlowMapConverter::read_flow_map(const char *file_name) {
  FILE *fin = fopen(file_name, "r");
  fclose(fin);
}
