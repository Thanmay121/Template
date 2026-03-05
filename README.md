# Raylib C++ Template

A C++ game template using [Raylib](https://www.raylib.com/).

## Prerequisites

Install Raylib for your platform before building:

- **Windows:** [raylib releases](https://github.com/raysan5/raylib/releases) or via `winget install raylib`
- **macOS:** `brew install raylib`
- **Linux (Debian/Ubuntu):** `sudo apt install libraylib-dev` or build from source

Also make sure you have:
- CMake 3.16+
- A C++17 compiler (MSVC, GCC, or Clang)

## Building

### Windows / Mac / Linux (CMake)

```bash
git clone https://github.com/YOUR_USERNAME/YOUR_REPO_NAME.git
cd YOUR_REPO_NAME
mkdir build && cd build
cmake ..
cmake --build .
```

The executable will be in the `build/` folder.

### Windows (Visual Studio)

Just open `Template.sln` directly in Visual Studio and hit **Run**.

## Project Structure

```
├── Source.cpp          # Entry point
├── player.cpp/hpp      # Player logic
├── enemyBase.cpp/hpp   # Enemy base class
├── animPlayer.cpp/hpp  # Animation system
├── base.cpp/hpp        # Base game class
├── collosion.hpp       # Collision helpers
└── Warrior/            # Sprite & texture assets
```
