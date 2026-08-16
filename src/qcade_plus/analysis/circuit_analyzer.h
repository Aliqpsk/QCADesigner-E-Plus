#ifndef QCADE_PLUS_CIRCUIT_ANALYZER_H
#define QCADE_PLUS_CIRCUIT_ANALYZER_H

/* QCADesigner-E+ analysis API. The implementation consumes the same DESIGN
 * model as the engine build; it does not duplicate QCA simulation physics. */
#include <glib.h>
#include "design.h"

typedef struct
{
  guint cell_count;
  guint cell_input_count;
  guint cell_output_count;
  guint bus_input_count;
  guint bus_output_count;
  guint input_count;
  guint output_count;
  guint layer_count;
  guint clock_zone_count;
  double width;
  double height;
  double area;
} QCADEPlusCircuitStats;

gboolean qcade_plus_analyze_design (DESIGN *design,
                                    QCADEPlusCircuitStats *stats);

#endif /* QCADE_PLUS_CIRCUIT_ANALYZER_H */
