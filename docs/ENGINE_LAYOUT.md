# Engine layout

QCADesigner-E+ keeps two representations of the upstream source during development.

```text
upstream/QCADesigner-E/   immutable pinned reference
            |
            | materialize-engine.sh
            v
engine/QCADesigner-E/     editable development source tree
```

The reference is pinned to commit `3bc90302bddacebfff838c74fb91cc56500387ea`.

The materialization script verifies the pin before copying the source. It excludes `.git` metadata so the resulting `engine/` directory is an ordinary editable source tree.

This arrangement lets regression tests compare the Plus engine against an unchanged upstream baseline while allowing source-level modifications to the engine.
