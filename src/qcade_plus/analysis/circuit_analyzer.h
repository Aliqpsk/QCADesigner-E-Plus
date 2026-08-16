#ifndef QCADE_PLUS_CIRCUIT_ANALYZER_H
#define QCADE_PLUS_CIRCUIT_ANALYZER_H

/*
 * QCADesigner-E+ analysis API.
 *
 * This layer intentionally depends on the existing QCADesigner-E DESIGN
 * model. It does not duplicate the QCA physics or simulation equations.
 */

#include <glib.h>
#include "../../../upstream/QCADesigner-E/QCADesignerE/src/design.h"

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

/* Analyze a loaded QCADesigner-E DESIGN. Returns FALSE for a NULL design. */
gboolean qcade_plus_analyze_design (DESIGN *design,
                                    QCADEPlusCircuitStats *stats);

#endif /* QCADE_PLUS_CIRCUIT_ANALYZER_H */
