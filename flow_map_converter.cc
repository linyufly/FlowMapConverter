// Author: Mingcheng Chen (linyufly@gmail.com)

#include "flow_map_converter.h"

#include <vtkStructuredPoints.h>
#include <vtkDoubleArray.h>
#include <vtkSmartPointer.h>
#include <vtkPointData.h>

#include <cstdio>
#include <cstdlib>

vtkStructuredPoints *FlowMapConverter::read_flow_map(const char *file_name) {
  FILE *fin = fopen(file_name, "r");

  vtkStructuredPoints *flow_map = vtkStructuredPoints::New();

  flow_map->SetOrigin(origin_);
  flow_map->SetSpacing(spacing_);
  flow_map->SetDimensions(dimensions_);

  vtkSmartPointer<vtkDoubleArray> last_positions =
      vtkSmartPointer<vtkDoubleArray>::New();

  last_positions->SetName("last_positions");
  last_positions->SetNumberOfComponents(3);
  last_positions->SetNumberOfTuples(dimensions_[0] *
                                    dimensions_[1] *
                                    dimensions_[2]);

  for (int x = 0; x < dimensions_[0]; x++) {
    for (int y = 0; y < dimensions_[1]; y++) {
      for (int z = 0; z < dimensions_[2]; z++) {
        double p_x, p_y, p_z;
        fscanf(fin, "%*d %*d %*d: %lf %lf %lf\n", &p_x, &p_y, &p_z);

        int index = (z * dimensions_[1] + y) * dimensions_[0] + x;
        last_positions->SetTuple3(index, p_x, p_y, p_z);
      }
    }
  }

  fclose(fin);

  flow_map->GetPointData()->SetScalars(last_positions);

  return flow_map;
}
