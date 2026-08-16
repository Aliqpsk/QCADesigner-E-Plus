# Compatibility Tests

This directory will contain golden QCA designs and reference simulation outputs.

## Required test classes

1. `.qca` parse tests
2. `.qca` save/round-trip tests
3. Cell geometry tests
4. Clock-zone tests
5. Bistable simulation tests
6. Coherence-vector simulation tests
7. Coherence-vector energy tests
8. Output/truth-table tests
9. Numerical regression tests with explicit tolerances

## Acceptance rule

A refactor is not considered safe if it changes reference simulation results without an explicitly documented scientific or numerical reason.

## Planned golden corpus

- inverter
- majority gate
- wire
- fan-out
- XOR
- NAND/NOR
- MUX/DEMUX
- full adder
- representative energy-analysis circuits
