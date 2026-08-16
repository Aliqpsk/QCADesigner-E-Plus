#include "energy_result.h"

double qcade_plus_energy_bath_total(const QCADEPlusEnergyChannels *channels)
{
  if (channels == 0)
    return 0.0;

  return channels->bath;
}

double qcade_plus_energy_channels_error_total(const QCADEPlusEnergyChannels *channels)
{
  if (channels == 0)
    return 0.0;

  return channels->bath +
         channels->clock +
         channels->io;
}
