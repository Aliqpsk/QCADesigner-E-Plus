#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SOURCE_URL="https://github.com/FSillT/QCADesigner-E.git"
SOURCE_REF="3bc90302bddacebfff838c74fb91cc56500387ea"
DEST="${ROOT_DIR}/engine-source/QCADesigner-E"
TMP_DIR="$(mktemp -d)"
trap 'rm -rf "${TMP_DIR}"' EXIT

echo "Cloning QCADesigner-E..."
git clone --filter=blob:none --no-checkout "${SOURCE_URL}" "${TMP_DIR}/QCADesigner-E"
cd "${TMP_DIR}/QCADesigner-E"
git checkout --detach "${SOURCE_REF}"

mkdir -p "${DEST}"
cp -a QCADesignerE/. "${DEST}/"

cat > "${DEST}/UPSTREAM_COMMIT" <<EOF
${SOURCE_REF}
EOF

echo "Imported QCADesigner-E at ${SOURCE_REF}"
echo "Source: ${SOURCE_URL}"
