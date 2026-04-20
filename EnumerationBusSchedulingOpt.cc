#include "EnumerationBusSchedulingOpt.hh"
#include <cassert>

void EnumerationBDS::First()
{ // start with configuration: F...FFFFFFT
  out.RemoveAll();
  out.InsertShift(0);
}

bool EnumerationBDS::Next()
{
  unsigned s = 0;

  while (out[s] && s < in.Shifts())
    {
      out.RemoveShift(s); //mettere e togliere true (insieme a insertshift)
      s++;
    }
  if (s == in.Shifts())  // TTTT...TTTT
    return false;
  else  // ....FTTT   -->  ...TFFF
    {
    out.InsertShift(s);
	  cerr << out << endl;
	  cin.get();
      return true;
    }
}

/*
bool EnumerationBDS::Next()
{
  unsigned s = 0, s1, c = 0, shifts;
  
  while (s < in.Shifts() - 1)
    {
      if (out[s])
        {
          if (out[s+1])
            c++;
          else
            {
              out.RemoveShift(s); 
              out.InsertShift(s+1);
              for (s1 = 0; s1 < c; s1++)
                {
                  out.RemoveShift(s-c+s1);
                  out.InsertShift(s1);
                }
			  // cerr << out << endl;
	          // cin.get();
              return true;
            }
        }
      s++;
    }

  if (out.Members() == in.Shifts())
    return false;
  shifts = out.Members();
  out.RemoveAll();
  for (s = 0; s <= shifts; s++)
    out.InsertShift(s);
  cerr << "Start with " << out.Members() << " shifts" << endl;
  return true;
}
*/

bool EnumerationBDS::Feasible()
{
  return out.Uncovered() == 0;
}


unsigned EnumerationBDS::Cost()
{
  return out.TotalCost();
}


