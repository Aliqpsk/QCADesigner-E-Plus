# Energy result regression contract

The energy adapter is considered compatible only when its reported channels can be traced to the upstream coherence-vector energy model.

Required channels:

- bath
- clock
- io
- input
- output

Required aggregate:

`total = bath + clock + io + input + output`

The test fixture must eventually compare the adapter output with an upstream run using identical design and simulation options. No tolerance is defined until an actual reference run is captured.
