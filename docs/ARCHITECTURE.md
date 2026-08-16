# QCADesigner-E-Plus Architecture

## 1. Mission

QCADesigner-E-Plus is a research-oriented fork of QCADesigner-E. The first priority is behavioral compatibility with the upstream application. New analysis and optimization features are added only after the reference behavior is protected by regression tests.

## 2. Upstream baseline

Reference project: https://github.com/FSillT/QCADesigner-E

Reference version: QCADesigner-E 2.2.

The upstream build is a C/GTK2/Autotools application. Its source tree separates the layout model, file I/O, editor/UI, simulation engines, simulation data, and energy-aware coherence-vector simulation.

## 3. Logical architecture

```text
QCADesigner-E-Plus
|
+-- Compatibility Core
|   +-- Cell model
|   +-- Design objects
|   +-- Layers
|   +-- Clock model
|   +-- Selection/editing
|   +-- QCA file I/O
|
+-- Simulation
|   +-- Bistable approximation
|   +-- Coherence vector
|   +-- Coherence vector + energy
|
+-- Analysis
|   +-- Cell count
|   +-- Area
|   +-- Layers / clock zones
|   +-- Latency
|   +-- Polarization traces
|   +-- Energy statistics
|
+-- Visualization
|   +-- Layout rendering
|   +-- Simulation graphs
|   +-- Energy-per-cell map
|   +-- Comparison views
|
+-- Optimization (later)
|   +-- Cell-count optimization
|   +-- Area optimization
|   +-- Latency optimization
|   +-- Energy optimization
|   +-- Multi-objective optimization
|
+-- Validation
    +-- Golden .qca designs
    +-- Reference outputs
    +-- Numerical tolerance checks
    +-- Round-trip file compatibility
```

## 4. Non-negotiable compatibility rules

1. A valid upstream `.qca` file must remain readable.
2. A saved compatible design must remain readable by QCADesigner/QCADesigner-E.
3. Existing simulation modes must retain their reference behavior until a deliberate versioned change is approved.
4. Energy calculations must be regression-tested before any optimization work.
5. Optimization is invalid unless logical behavior/truth-table behavior is preserved.

## 5. Development phases

### Phase 0 — Baseline

- Import/reference upstream source.
- Reproduce the upstream build.
- Record compiler/dependency requirements.
- Establish golden designs and expected outputs.

### Phase 1 — Compatibility layer

- Isolate file format and design model interfaces.
- Add regression tests around the existing engines.

### Phase 2 — Analysis

- Expose simulation results through stable data structures.
- Add statistics and export.

### Phase 3 — Visualization

- Add energy-per-cell visualization.
- Add simulation traces and comparison dashboards.

### Phase 4 — Optimization

- Add constrained optimization only after correctness is protected.

### Phase 5 — Modern UI

- Consider replacing the legacy GTK2 presentation layer only after the core and compatibility test suite are stable.

## 6. Scientific integrity

The project must distinguish between:

- **Reference-compatible mode:** reproduces upstream behavior.
- **Extended mode:** intentionally introduces a new model, numerical method, or analysis.

The two modes must never be silently mixed.
