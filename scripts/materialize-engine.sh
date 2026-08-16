#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
UPSTREAM_DIR="$ROOT_DIR/upstream/QCADesigner-E"
ENGINE_DIR="$ROOT_DIR/engine/QCADesigner-E"
UPSTREAM_COMMIT="3bc90302bddacebfff838c74fb91cc56500387ea"

if [[ ! -d "$UPSTREAM_DIR/.git" && ! -f "$UPSTREAM_DIR/.git" ]]; then
  echo "Upstream submodule is not initialized: $UPSTREAM_DIR" >&2
  exit 1
fi

actual="$(git -C "$UPSTREAM_DIR" rev-parse HEAD)"
if [[ "$actual" != "$UPSTREAM_COMMIT" ]]; then
  echo "Unexpected upstream commit: $actual" >&2
  echo "Expected: $UPSTREAM_COMMIT" >&2
  exit 1
fi

mkdir -p "$ROOT_DIR/engine"
rm -rf "$ENGINE_DIR"
mkdir -p "$ENGINE_DIR"

# Materialize a development copy while leaving the upstream submodule untouched.
# .git metadata is deliberately excluded so engine/ is an ordinary source tree.
tar -C "$UPSTREAM_DIR" --exclude=.git -cf - . | tar -C "$ENGINE_DIR" -xf -

cat > "$ENGINE_DIR/UPSTREAM_BASELINE.txt" <<EOF
QCADesigner-E development engine copy

Source repository: https://github.com/FSillT/QCADesigner-E
Pinned upstream commit: $UPSTREAM_COMMIT

The upstream/ submodule remains the immutable scientific reference.
This directory is the source tree intended for QCADesigner-E+ modifications.
EOF

echo "Materialized engine at: $ENGINE_DIR"
echo "Upstream baseline:      $UPSTREAM_COMMIT"
