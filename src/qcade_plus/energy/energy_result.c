#include "energy_result.h"

double qcade_plus_energy_channels_total(const QCADEPlusEnergyChannels *channels)
{
  if (channels == 0)
    return 0.0;

  return channels->bath +
         channels->clock +
         channels->io +
         channels->input +
         channels->output;
}
