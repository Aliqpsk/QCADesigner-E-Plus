#ifndef QCADE_PLUS_ENERGY_RESULT_H
#define QCADE_PLUS_ENERGY_RESULT_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Public, physics-neutral representation of one QCADesigner-E energy result.
 * Values are copied from the upstream engine; this layer does not redefine
 * the underlying energy model.
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

/* Sum the five upstream channels without changing their definitions. */
double qcade_plus_energy_channels_total(const QCADEPlusEnergyChannels *channels);

#ifdef __cplusplus
}
#endif

#endif
