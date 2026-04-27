#include "WL_Enumeration.hh"

// Insert here the code in the method of class EnumerationWLOpt

void EnumerationWLOpt::First()
{
  // start with configuration: [0, 0, 0, 0, ..., S-1]
  unsigned s;
  for (s = 0; s < in.Stores(); s++)
    out.Assign(s, 0);
}

bool EnumerationWLOpt::Next()
{
  // starting from dx to sx 
  unsigned s = in.Stores();
  do {
    if (s == 0)
      return false;
    s--; // start with -1 bc we go from 0 to n-1
  } while (out.Assignment(s) == (int)(in.Warehouses() - 1)); 

  // increase the assignment of store s
  out.Assign(s, out.Assignment(s) + 1);

  // reset the rightmost assignments to 0
  unsigned s1;
  for (s1 = s + 1; s1 < in.Stores(); s1++)
    out.Assign(s1, 0);

  return true;
}

bool EnumerationWLOpt::Feasible()
{
  return out.ComputeViolations() == 0;
}

unsigned EnumerationWLOpt::Cost()
{
  return out.ComputeCost();
}


/* -- OUTPUT:
      wlp1 -> Best solution found [0, 0, 0], (40) after  2 iterations
      wlp2 -> Best solution found [1, 0, 0, 0, 1, 0], (39, 32) after  65 iterations
      wlp3 -> Best solution found [1, 2, 2, 1, 1, 1, 2], (0, 50, 29) after  2188 iterations
      wlp4 -> Best solution found [2, 0, 0, 1, 3, 0, 2, 1, 2, 3, 0], (53, 28, 40, 27) after  4194305 iterations
      wlp5 -> Best solution found [0, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 0, 2], (61, 0, 95, 0, 0) after  1220703126 iterations
      wlp6 -> New best solution [0, 0, 5, 1, 4, 1, 1, 1, 5, 5, 5, 4, 0, 1, 1], (34, 63, 0, 0, 24, 44) (cost 6169)  found after 11500890200 iterations
      wlp7 -> New best solution [0, 0, 0, 0, 2, 2, 2, 5, 6, 1, 1, 1, 2, 6, 5, 1, 6], (40, 48, 34, 0, 0, 25, 50) (cost 8002)  found after 32439500345 iterations
      wlp8 -> New best solution [0, 0, 0, 0, 0, 0, 0, 7, 4, 2, 5, 2, 4, 4, 4, 5, 7, 7], (80, 0, 32, 0, 41, 32, 0, 36) (cost 10531)  found after 8097778048 iterations
      wlp9 -> any in 3min
      wlp10 -> any in 3min
*/
