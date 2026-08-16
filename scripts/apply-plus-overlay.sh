#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
ENGINE_DIR="$ROOT_DIR/engine/QCADesigner-E"
OVERLAY_DIR="$ROOT_DIR/engine-overlay"

if [[ ! -d "$ENGINE_DIR" ]]; then
  echo "Engine tree is missing. Run scripts/materialize-engine.sh first." >&2
  exit 1
fi
if [[ ! -d "$OVERLAY_DIR" ]]; then
  echo "Plus overlay is missing: $OVERLAY_DIR" >&2
  exit 1
fi

# Copy only explicitly maintained Plus changes into the materialized engine.
# Keeping the overlay separate makes upstream synchronization auditable.
while IFS= read -r -d '' src; do
  rel="${src#"$OVERLAY_DIR/"}"
  dst="$ENGINE_DIR/$rel"
  mkdir -p "$(dirname "$dst")"
  cp "$src" "$dst"
done < <(find "$OVERLAY_DIR" -type f -print0)

echo "Applied QCADesigner-E+ overlay to: $ENGINE_DIR"
