# Energy Analysis Architecture

QCADesigner-E+ treats the upstream QCADesigner-E coherence-vector energy engine as the scientific reference. The Plus layer must not duplicate or reinterpret the physics equations during the compatibility phase.

## Data flow

```text
coherence_model (upstream)
        |
        v
Energy Export Adapter
        |
        v
QCADEPlusEnergyResult
   |         |
   v         v
Global     Per-cell
channels   channels
```

## Upstream channels

The upstream energy model tracks:

- bath dissipation
- clock dissipation
- I/O dissipation
- input-side dissipation
- output-side dissipation

The Plus API keeps these names intact. Any later mapping to terms such as leakage or switching must be explicitly documented and validated against the upstream equations.

## Compatibility rule

Energy values produced by the Plus adapter must be compared against the upstream reference before the GUI exposes them as scientific results.
