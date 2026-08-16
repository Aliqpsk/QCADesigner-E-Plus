#ifndef QCADE_PLUS_ENERGY_RESULT_H
#define QCADE_PLUS_ENERGY_RESULT_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Public, physics-neutral representation of one QCADesigner-E energy result.
 * Values are copied from the upstream engine; this layer does not redefine
 * the underlying energy model.
 *
 * Compatibility note: upstream's printed "Total energy dissipation" is based
 * on the integrated bath channel. Its "E_Error_total" combines bath + clock
 * + I/O. Input/output channels are reported separately and are not silently
 * added to either upstream aggregate.
 */
typedef struct
{
  double bath;
  double clock;
  double io;
  double input;
  double output;
  double total;
} QCADEPlusEnergyChannels;

typedef struct
{
  unsigned long sample_count;
  unsigned long clock_cycles;
  double time_step;
  QCADEPlusEnergyChannels integrated;
} QCADEPlusEnergyResult;

/* Upstream-compatible aggregate: bath + clock + I/O. */
double qcade_plus_energy_channels_error_total(const QCADEPlusEnergyChannels *channels);

/* Upstream-compatible reported total energy: bath only. */
double qcade_plus_energy_bath_total(const QCADEPlusEnergyChannels *channels);

#ifdef __cplusplus
}
#endif

#endif
