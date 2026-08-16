# Upstream Baseline

## Reference

- Repository: https://github.com/FSillT/QCADesigner-E
- Baseline: QCADesigner-E 2.2
- License/attribution: retain all upstream notices and GPL terms when redistributing upstream-derived code.

## Observed build model

The upstream project uses C, GTK2, Autotools, and Makefiles. A documented Linux build path is to install `automake` and `libgtk2.0-dev`, clone the repository, enter `QCADesignerE`, run `./configure`, then `make`.

The Windows distribution uses a GTK2 runtime and an Inno Setup installer.

## Important source areas

The upstream `QCADesignerE/src` tree contains the core design model, editor/UI, file I/O, simulation engines, simulation data, and energy-aware coherence-vector implementation.

Key simulation components include:

- `bistable_simulation`
- `coherence_vector`
- `coherence_vector_energy`
- `simulation`
- `simulation_data`

Key design/model components include:

- `QCADCell`
- `QCADDesignObject`
- `QCADLayer`
- `QCADDOContainer`
- `QCADCompoundDO`

## Rule

Do not rewrite the scientific engine merely to modernize the interface. First establish a passing reference build and regression suite. UI modernization is a later phase.
