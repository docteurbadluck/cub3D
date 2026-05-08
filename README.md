
# 🧱 Cub3D

**Cub3D** is a small 3D game engine inspired by *Wolfenstein 3D*, built with **raycasting** and the **MiniLibX** library.  
The goal is to explore graphics programming, math, and architecture through a simple first-person view engine.  
collaborator : jholter

<img width="800" height="800" alt="cub3D" src="https://github.com/user-attachments/assets/6adbbb7d-02e8-4392-b4d3-66de0259c3cd" />

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

- I’ve tried to **apply Clean Architecture** concepts to separate logic and rendering. (invert dependencies, single responsability principal)    
- To run the project on your computer, **update the texture paths** in your map file to match your local setup.

## 🛠️ Build & Run
make
./build/cub3d test.cub
