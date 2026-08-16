# QCADesigner-E+ Analysis Layer

This directory contains the product-specific analysis adapter.

## Circuit statistics contract

`qcade_plus_analyze_design()` consumes the application's existing QCADesigner-E `DESIGN` model. It must never create a second design representation and must not mutate the design or simulation state.

The returned statistics cover:

- cell count
- input/output cell counts
- input/output bus counts
- total input/output counts
- layer count
- clock-zone count
- bounding width and height
- bounding area

The GUI integration must pass the currently open `project_options.design` to this API. Energy quantities remain in the energy-analysis layer and are not fabricated by the circuit-statistics adapter.
