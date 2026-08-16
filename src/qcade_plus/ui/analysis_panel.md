# QCADesigner-E+ Analysis Panel Contract

This file defines the first UI contract for the analysis panel. It is intentionally backend-neutral so the panel can be integrated into the existing QCADesigner-E GTK workspace without duplicating the canvas or editor.

## Circuit Statistics

Fields:

- Cells
- Cell Inputs
- Cell Outputs
- Bus Inputs
- Bus Outputs
- Total Inputs
- Total Outputs
- Layers
- Clock Zones
- Width
- Height
- Area

## Energy Analysis

Fields:

- Bath dissipation
- Clock dissipation
- I/O dissipation
- Input-side dissipation
- Output-side dissipation
- Upstream-compatible error aggregate (Bath + Clock + I/O)

## State

- No design loaded: show `No design loaded`.
- Design loaded but not simulated: statistics available; energy fields show `Not simulated`.
- Energy simulation completed: show validated energy values and simulation settings.

## Safety

The panel is read-only. Opening or refreshing analysis must never modify the DESIGN object, cell positions, clock zones, or simulation settings.
