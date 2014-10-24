// Author: Mingcheng Chen (linyufly@gmail.com)

#include "flow_map_converter.h"

#include <vtkStructuredPointsWriter.h>
#include <vtkStructuredPoints.h>
#include <vtkPointData.h>
#include <vtkSmartPointer.h>
#include <vtkDataArray.h>

const char *kDataFile = "data/gyre_last_positions.txt";
const char *kOutputFile = "flow_map.vtk";
const double kSpacing[3] = {0.015, 0.015, 0.015};
const double kOrigin[3] = {0.0, -1.5, 0.0};
const int kDimensions[3] = {101, 201, 201};

void flow_map_converter_test() {
  printf("flow_map_converter_test {\n");

  FlowMapConverter converter;
  converter.set_origin(kOrigin[0], kOrigin[1], kOrigin[2]);
  converter.set_spacing(kSpacing[0], kSpacing[1], kSpacing[2]);
  converter.set_dimensions(kDimensions[0], kDimensions[1], kDimensions[2]);

  vtkStructuredPoints *flow_map = converter.read_flow_map(kDataFile);

  vtkSmartPointer<vtkStructuredPointsWriter> writer =
      vtkSmartPointer<vtkStructuredPointsWriter>::New();
  writer->SetFileName(kOutputFile);
  writer->SetInputData(flow_map);
  writer->Write();

  printf("Finished writing.\n");
  int count = 10;
  for (int i = 0; count && i < kDimensions[0]; i++) {
    for (int j = 0; count && j < kDimensions[1]; j++) {
      for (int k = 0; count && k < kDimensions[2]; k++) {
        int index = (k * kDimensions[1] + j) * kDimensions[0] + i;
        double position[3];
        flow_map->GetPointData()->GetScalars()->GetTuple(index, position);
        printf("%lf %lf %lf\n", position[0], position[1], position[2]);
        count--;
      }
    }
  }

  if (flow_map) {
    flow_map->Delete();
  }

  printf("} flow_map_converter_test\n");
}

int main() {
  flow_map_converter_test();

  return 0;
}
