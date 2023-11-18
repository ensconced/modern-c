#include <float.h>
#include <math.h>
#include <stdio.h>

double square(double x) { return x * x; }

double differentiate(double x) {
  double e = sqrt(DBL_EPSILON);
  double y1 = square(x - e);
  double y2 = square(x + e);
  return (y2 - y1) / (2 * e);
}
