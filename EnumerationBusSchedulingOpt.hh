#include "EnumerationOpt.hh"
#include "BDS_Data.hh"

class EnumerationBDS : public EnumerationOpt<BDS_Input, BDS_Output, unsigned>
{
public:
  EnumerationBDS(const BDS_Input& in) : EnumerationOpt(in) {}
protected:
  void First() override;
  bool Next() override;
  bool Feasible() override;
  unsigned Cost() override;
};

