# 🧱 Cub3D

**Cub3D** is a small 3D game engine inspired by *Wolfenstein 3D*, built with **raycasting** and the **MiniLibX** library.  
The goal is to explore graphics programming, math, and architecture through a simple first-person view engine.
collaborator : jholter
<img width="801" height="806" alt="Screenshot from 2025-10-28 16-15-05" src="https://github.com/user-attachments/assets/6a7cf7e7-58bd-4fdd-a023-c6bfa60d07f2" />

---

## 🎯 Objectives

- Implement a minimal **raycasting engine**  
- Handle **movement**, **rotation**, and **collision**  
- Parse and validate a **custom map file**  
- Display **walls, textures, and colors**  
- Experiment with **Clean Architecture** principles in C

---

## ⚙️ Controls

| Key | Action |
|-----|--------|
| `W` / `S` | Move forward / backward |
| `A` / `D` | Strafe left / right |
| ⬅️ / ➡️ | Rotate camera | 
| `ESC` | Exit |

## 🧠 Notes

- I’ve tried to **apply Clean Architecture** concepts to separate logic and rendering.  
- To run the project on your computer, **update the texture paths** in your map file to match your local setup.

## 🛠️ Build & Run
make
**update the texture paths in test.cub to match your config** 
./build/cub3d test.cub
