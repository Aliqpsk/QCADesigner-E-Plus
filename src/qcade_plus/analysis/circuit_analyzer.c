#include "circuit_analyzer.h"

#include <string.h>

static void count_layer_object (QCADDesignObject *object, gpointer user_data)
{
  QCADEPlusCircuitStats *stats = (QCADEPlusCircuitStats *) user_data;
  QCADCell *cell;

  if (!QCAD_IS_CELL (object))
    return;

  cell = QCAD_CELL (object);
  stats->cell_count++;

  if (cell->cell_function == QCAD_CELL_INPUT)
  {
    stats->cell_input_count++;
    stats->input_count++;
  }
  else if (cell->cell_function == QCAD_CELL_OUTPUT)
  {
    stats->cell_output_count++;
    stats->output_count++;
  }

  if (cell->cell_options.clock >= 0 &&
      (guint) (cell->cell_options.clock + 1) > stats->clock_zone_count)
    stats->clock_zone_count = (guint) cell->cell_options.clock + 1;
}

static guint count_buses_of_function (BUS_LAYOUT *bus_layout,
                                      QCADCellFunction function)
{
  guint count = 0;
  int i;

  if (bus_layout == NULL || bus_layout->buses == NULL)
    return 0;

  for (i = 0; i < bus_layout->buses->icUsed; i++)
  {
    BUS *bus = exp_array_index_1d (bus_layout->buses, BUS *, i);

    if (bus != NULL && bus->bus_function == function)
      count++;
  }

  return count;
}

gboolean qcade_plus_analyze_design (DESIGN *design,
                                    QCADEPlusCircuitStats *stats)
{
  GList *iter;
  WorldRectangle extents;

  if (design == NULL || stats == NULL)
    return FALSE;

  memset (stats, 0, sizeof (*stats));
  stats->layer_count = (guint) g_list_length (design->lstLayers);

  for (iter = design->lstLayers; iter != NULL; iter = iter->next)
  {
    QCADLayer *layer = QCAD_LAYER (iter->data);
    if (layer == NULL)
      continue;
    qcad_layer_objects_foreach (layer, FALSE, TRUE,
                                count_layer_object, stats);
  }

  if (design->bus_layout != NULL)
  {
    stats->bus_input_count = count_buses_of_function (design->bus_layout,
                                                       QCAD_CELL_INPUT);
    stats->bus_output_count = count_buses_of_function (design->bus_layout,
                                                        QCAD_CELL_OUTPUT);
    stats->input_count += stats->bus_input_count;
    stats->output_count += stats->bus_output_count;
  }

  if (design_get_extents (design, &extents, FALSE))
  {
    stats->width = extents.cxWorld;
    stats->height = extents.cyWorld;
    stats->area = stats->width * stats->height;
  }

  return TRUE;
}
