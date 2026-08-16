#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
ENGINE_DIR="${ROOT_DIR}/engine/QCADesigner-E"
PATCH_DIR="${ROOT_DIR}/engine-overlay/patches"

if [[ ! -d "${ENGINE_DIR}" ]]; then
  echo "error: engine source is missing: ${ENGINE_DIR}" >&2
  echo "run scripts/materialize-engine.sh first" >&2
  exit 1
fi

# Only apply real unified diffs. Documentation/specification files are ignored.
shopt -s nullglob
patches=("${PATCH_DIR}"/*.diff "${PATCH_DIR}"/*.patch)
for patch_file in "${patches[@]}"; do
  if grep -q '^# QCADesigner-E+ GUI patch specification' "${patch_file}" || \
     grep -q '^# QCADesigner-E+ GUI integration patch' "${patch_file}"; then
    echo "staging specification: ${patch_file}"
    continue
  fi
  echo "applying: ${patch_file}"
  git -C "${ENGINE_DIR}" apply --check "${patch_file}"
  git -C "${ENGINE_DIR}" apply "${patch_file}"
done
