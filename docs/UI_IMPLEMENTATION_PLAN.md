# QCADesigner-E+ UI Implementation Plan

The Plus interface will preserve the familiar QCADesigner-E workflow while adding analysis without disrupting circuit editing.

## Main workspace

- Menu bar
- Toolbar
- Tool palette
- QCA canvas
- Status bar
- Properties/selection area

## Plus panels

### Circuit Statistics

Displays cell count, inputs, outputs, layers, clock zones, and geometry.

### Energy Analysis

Displays the upstream-compatible bath, clock, I/O, input, and output channels. Aggregates must retain the upstream semantics.

### Energy Map

A visual overlay on the QCA canvas. It will only be enabled when validated per-cell energy data are available from the engine.

## Interaction rules

1. Editing behavior remains compatible with the upstream workflow.
2. Analysis views are read-only until a later optimization feature is explicitly introduced.
3. Analysis must never mutate the circuit.
4. Scientific values must identify their simulation model and settings.
5. No energy color scale is shown until per-cell reference data have been validated.
