# Engine overlay patches

Patch files in this directory are applied after the pinned upstream source is materialized.

Only actual unified-diff files are applied. Files containing the current GUI integration
specifications are staging documents and are intentionally skipped by the overlay script.

A patch is promoted to an executable patch only after it has been generated against the
materialized upstream commit and passes `git apply --check` in CI.
