# QCADesigner-E+ Development Status

## Baseline

The project uses the official QCADesigner-E source as its scientific and compatibility reference. The original simulation engines are not being rewritten during the baseline phase.

## Current architecture

- Upstream QCADesigner-E: reference implementation
- QCA model: cells, layers, clock zones, design objects
- File I/O: `.qca` compatibility
- Simulation: Bistable, Coherence Vector, Coherence Vector + Energy
- QCADesigner-E+ layer: analysis, visualization, and later optimization

## First product feature

The first QCADesigner-E+ feature is a non-invasive circuit analysis layer. It will expose circuit statistics without changing the underlying physics engine:

- cell count
- input/output count
- layer count
- clock-zone count
- bounding-box dimensions and area
- later: latency and simulation/energy metrics

## Rules

1. Do not change the original physics equations during baseline validation.
2. Preserve `.qca` compatibility.
3. Add regression tests before optimization.
4. Never claim simulation compatibility without measured comparison against the reference.
5. Keep `main` stable; development work belongs on `development` until validated.
