# Rover Control

This repository contains a C++ project for controlling a tiny car. It supports:
- **Host unit tests** (GoogleTest, native build)
- **ESP32 firmware** (ESP-IDF-based cross-compile)

---

## Supported platforms

- Ubuntu 22.04 / 24.04
- Windows 10 / 11 (via WSL2 with Ubuntu, or MSYS2/MinGW for native)

---

## Build modes

This project uses a single `build/` directory with mode-specific subfolders.

| Command | What it does |
|---|---|
| `-DBUILD_MODE=native` | Builds unit tests for the host machine |
| `-DBUILD_MODE=esp32` | Builds firmware for the ESP32 target |

The default mode is **`native`**.

---

## 1) Unit tests (native / host build)

### Ubuntu prerequisites

```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake libgtest-dev
```

Windows prerequisites (native):
- [Visual Studio 2022](https://visualstudio.microsoft.com/) with "Desktop development with C++" workload, **or**
- [MSYS2](https://www.msys2.org/) + `pacman -S base-devel mingw-w64-x86_64-gcc cmake`

If you use MSYS2, run the MSYS2 MinGW64 terminal and configure from there so `cmake` and `g++` are on PATH.

### Configure, build, and run tests

From the project root:

```bash
cmake -S . -B build/native -DBUILD_MODE=native
cmake --build build/native --target rover_tests -j
ctest --test-dir build/native --output-on-failure
```

All tests are GoogleTest-based and discovered automatically by CTest from the `tests/` directory.

---

## 2) ESP32 firmware

### Install ESP-IDF

The ESP32 target uses [ESP-IDF](https://idf.espressif.com/) as the build system / SDK. Below is a summary of their [Getting Started](https://docs.espressif.com/projects/esp-idf/en/v6.0.1/esp32/get-started/linux-setup.html#install-eim-linux-apt) section.

The ESP-IDF VS Code Extension is highly recommended.

#### Ubuntu

First, use apt to get the ESP-IDF installer (eim):
```bash
sudo apt-get update
echo "deb [trusted=yes] https://dl.espressif.com/dl/eim/apt/ stable main" | sudo tee /etc/apt/sources.list.d/espressif.list
sudo apt update

sudo apt install eim  # GUI and CLI
# sudo apt install eim-cli  # CLI only

```

Now run the installer to get ESP-IDF:

```bash
eim install -i v6.0.1
```

#### Windows

The recommended route on Windows is **WSL2 + Ubuntu**. Follow the Ubuntu steps inside your WSL2 distro. This is the most supported route.

Otherwise, go to https://dl.espressif.com/dl/eim/ to download the ESP-IDF Installation Manager (EIM). Follow instructions on the [espressif docs page](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/windows-setup.html) for installation.

### Build the ESP32 firmware

With ESP-IDF installed:

```bash
cmake -S . -B build/esp32 -DBUILD_MODE=esp32 -DCMAKE_TOOLCHAIN_FILE=${IDF_PATH}/tools/cmake/toolchain/esp32_toolchain.cmake
cmake --build build/esp32 --target rover_esp32_app -j
```

`IDF_PATH` is set by `export.sh`. If you used a custom install path, substitute it accordingly.

---

## Quick reference

- **Q: What if I pass `-DCMAKE_TOOLCHAIN_FILE=...` but forget `-DBUILD_MODE=esp32`?**
  - A: CMake auto-detects the toolchain and switches to ESP32 mode with a warning.

- **Q: How do I build just the test target?**
  - A: `cmake --build build/native --target rover_tests -j`

- **Q: How do I build just the ESP32 app?**
  - A: `cmake --build build/esp32 --target rover_esp32_app -j`

- **Q: Can I have both build trees at the same time?**
  - A: Yes, because they are in `build/native` and `build/esp32` subfolders.

---

## Repository layout

- `src/rover-core` - Platform-agnostic core logic
- `src/rover-mock` – Test doubles
- `src/rover-esp32` – ESP32-specific `main.cpp` and drivers
- `tests` – GoogleTest unit tests
- `build` – generated build outputs (gitignored)
