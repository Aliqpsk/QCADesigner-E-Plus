# Circuit Analyzer regression contract

This fixture defines the first regression contract for `QCADEPlusCircuitStats`.

## Required invariants

For every valid `DESIGN`:

1. `cell_count` equals the number of `QCADCell` objects visited in all design layers.
2. `cell_input_count + cell_output_count` counts only cells whose `cell_function` is input or output.
3. `bus_input_count` and `bus_output_count` are counted independently from the bus layout.
4. `input_count == cell_input_count + bus_input_count`.
5. `output_count == cell_output_count + bus_output_count`.
6. `layer_count` equals the number of layers in `design->lstLayers`.
7. `width`, `height`, and `area` are derived from `design_get_extents()`.
8. The analyzer must not mutate the `DESIGN`.

## Why this is a contract first

The repository currently keeps the upstream source as the scientific reference. A regression test must be based on observed upstream data before hard-coded numeric expectations are introduced. The next test implementation will load a real `.qca` fixture and record its reference statistics.
