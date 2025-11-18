# 🎮 SFML Projects – C++17 + SFML 3.0.2

This repository contains a set of applications built with **C++17** and **SFML 3.0.2**, developed incrementally to explore graphics, audio, and game mechanics.  
All examples were compiled and tested on **Windows (MSYS2 MINGW64)**, but instructions for Linux are also provided.

🔗 Repository: [alexanderPeregrina/sfml_projects](https://github.com/alexanderPeregrina/sfml_projects)

---

## 🧩 Applications Included

The apps are organized by increasing complexity:

### 1. 🖼️ Background with Music
- Opens a window with a background image.
- Plays background music using SFML’s audio module.
- Demonstrates basic window creation, texture loading, and audio playback.

### 2. ⚽ Bouncing Ball
- Displays a ball that moves and bounces off the window edges.
- Introduces simple physics and collision detection.
- Great starting point for understanding SFML’s rendering loop.

### 3. 🚀 Random Walk (Spaceship)
- A spaceship sprite moves randomly across the screen.
- Demonstrates random number generation and sprite movement.
- Useful for learning about transformations and sprite handling.

### 4. 🧱 Breakout Game
- Classic brick-breaking arcade game.
- Features paddle control, ball physics, brick collision, and scoring.
- Combines all previous concepts into a complete playable game.

---

## 🛠️ Installation Instructions

### Windows (MSYS2 MINGW64)

1. **Install MSYS2**  
   Download from [https://www.msys2.org](https://www.msys2.org).

2. **Update MSYS2**  
   ```bash
   pacman -Syu
   # Restart terminal
   pacman -Su
   ```

3. **Install C++ Compiler and SFML**
```bash
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-SFML
```

4. **Verify Installation**
```bash
g++ --version
pacman -Q | grep SFML
```

## Linux (Debian/Ubuntu-based)

1. Install C++ Compiler
```bash
sudo apt update
sudo apt install g++ build-essential
```

2. Install SFML
```bash
 sudo apt install libsfml-dev
```

3. Verify Installation
```bash
g++ --version
dpkg -l | grep sfml
```

## 🚀 Compile and Run Breakout Game

From the repository root, run:

```bash
g++ -std=c++17 -O2 breakout_game.cpp background.cpp ball.cpp brick.cpp brick_handler.cpp paddle.cpp -o breakout_game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```

Then execute:./breakout_game
## 📌 Notes- All apps use SFML 3.0.2 with C++17.
- Designed for incremental learning: from simple window creation to a full arcade game.
- Tested on Windows (MSYS2 MINGW64), but also works on Linux with libsfml-dev.
📜 LicenseThis project is open-source and available under the MIT License.
