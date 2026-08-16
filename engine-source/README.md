# Engine Source Development Branch

This branch is reserved for a materialized, editable copy of the pinned QCADesigner-E source.

Reference upstream commit: `3bc90302bddacebfff838c74fb91cc56500387ea`

The `development` branch keeps the upstream project as a submodule and uses the materialization/overlay build flow. This branch exists as a staging point for importing the complete engine source before GUI and simulation patches are maintained as normal repository files.

Do not treat this README as the engine source itself. A release candidate is not considered complete until the full upstream source tree is present and the normal build passes without materialization.
