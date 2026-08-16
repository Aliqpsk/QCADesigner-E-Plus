# Build the QCADesigner-E-Plus baseline

The first development milestone builds the upstream QCADesigner-E reference without changing its simulation code.

## Linux

Install the build dependencies required by the upstream Autotools project:

```bash
sudo apt-get update
sudo apt-get install -y autoconf automake gettext libgtk2.0-dev libtool pkg-config
```

Initialize the upstream submodule:

```bash
git submodule update --init --recursive
```

Build it:

```bash
bash scripts/build-upstream.sh
```

The executable is produced under:

```text
build/upstream/install/bin/QCADesigner
```

## Reference point

The upstream submodule is pinned to a specific QCADesigner-E commit. Do not update that commit casually: it is the scientific/reference baseline for compatibility and regression testing.

The upstream project documents the same Autotools flow (`configure`, `make`, `make install`) and describes QCADesigner-E as an extension of QCADesigner with an additional CVSE-based energy simulation module.

## Windows

Windows packaging will be added after the Linux baseline builds reproducibly. We will not change the simulation engine merely to make the first Windows build easier.
