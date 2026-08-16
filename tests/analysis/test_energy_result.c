#include <assert.h>
#include <math.h>
#include "../../src/qcade_plus/energy/energy_result.h"

int main(void)
{
  QCADEPlusEnergyChannels e = {1.0, 2.0, 3.0, 4.0, 5.0, 0.0};
  double total = qcade_plus_energy_channels_total(&e);

  assert(fabs(total - 15.0) < 1e-12);
  return 0;
}
