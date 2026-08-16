# QCADesigner-E+ Analysis Layer

This directory is reserved for the first product-specific analysis layer.

The analysis layer must consume the existing QCADesigner-E design/simulation data rather than duplicating the physics model.

Planned API:

- `cell_count`
- `input_count`
- `output_count`
- `layer_count`
- `clock_zone_count`
- `bounding_width`
- `bounding_height`
- `bounding_area`

Later stages will add latency and energy metrics after regression fixtures establish reference behavior.
