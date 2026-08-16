#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
UPSTREAM_DIR="$ROOT_DIR/upstream/QCADesigner-E/QCADesignerE"
BUILD_DIR="$ROOT_DIR/build/upstream"
INSTALL_DIR="$BUILD_DIR/install"

if [[ ! -f "$UPSTREAM_DIR/configure" ]]; then
  echo "Upstream submodule is not initialized. Run:"
  echo "  git submodule update --init --recursive"
  exit 1
fi

mkdir -p "$BUILD_DIR"
cd "$UPSTREAM_DIR"

if [[ ! -f Makefile ]]; then
  ./configure --prefix="$INSTALL_DIR"
fi

make -j"$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 2)"
make install

echo
echo "Built QCADesigner-E upstream baseline:"
echo "  $INSTALL_DIR/bin/QCADesigner"
