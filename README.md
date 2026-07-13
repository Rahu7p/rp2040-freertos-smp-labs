# RP2040 FreeRTOS SMP Labs

> A complete laboratory manual for learning multicore embedded systems using the RP2040 and FreeRTOS SMP.

---

**Author:** Raúl Peña Ortega

**Institution:** Tecnológico de Monterrey

---

<p align="center">

<img src="assets/logo/cEmb.png" width="900">

</p>

# Overview

This repository contains a complete laboratory manual designed for undergraduate Embedded Systems courses.

The manual introduces multicore embedded programming using the **Raspberry Pi RP2040** microcontroller and the **FreeRTOS SMP** kernel through a combination of concise theoretical chapters and hands-on laboratory activities.

The material emphasizes experimentation, allowing students to observe, analyze, and understand the behavior of multicore embedded systems before developing their own applications.

---

# Features

- RP2040 dual-core architecture
- FreeRTOS SMP
- Hands-on laboratory activities
- Fully self-contained Template Project
- Step-by-step development environment setup
- Multicore scheduling experiments
- Task communication and synchronization
- Cross-platform development (Windows, Linux, and macOS)

---

# Documentation

| Section | Description | Status |
|----------|-------------|:------:|
| Getting Started | Repository overview | ✅ |
| Chapter 0 | Development Environment | ✅ |
| Chapter 1 | Why do Embedded Systems Need More Than One Processor Core? | ✅ |
| Chapter 2 | Task Communication and Synchronization | 🚧 |
| Laboratory 1 | Discovering the FreeRTOS SMP Scheduler | ✅ |
| Laboratory 2 | Designing Multicore Applications | 🚧 |
| Troubleshooting | Common problems and solutions | 🚧 |
| References | Books and official documentation | 🚧 |

---

# Learning Path

Complete the manual in the following order.

1. Chapter 0 — Development Environment
2. Chapter 1 — Why do Embedded Systems Need More Than One Processor Core?
3. Laboratory 1 — Discovering the FreeRTOS SMP Scheduler
4. Chapter 2 — Task Communication and Synchronization
5. Laboratory 2 — Designing Multicore Applications

Each chapter prepares the concepts required for the following laboratory.

---

# Hardware

The laboratories were designed using the following hardware.

- Pololu Zumo RP2040 Robot
- Raspberry Pi Pico (compatible)

---

# Software

The following software is required.

| Tool | Version |
|------|---------|
| Visual Studio Code | Latest |
| Raspberry Pi Pico Extension | Latest |
| Pico SDK | 2.3.0 |
| FreeRTOS Kernel | V11.x |
| Git | Latest |

> [!NOTE]
>
> The Raspberry Pi Pico Extension automatically installs and configures the required development tools, including the ARM GNU Toolchain, CMake, Ninja, OpenOCD, and picotool.

---

# Repository Structure

```text
rp2040-freertos-smp-labs/
│
├── assets/
│
├── docs/
│   ├── chapter00/
│   ├── chapter01/
│   ├── chapter02/
│   │
│   ├── labs/
│   │   ├── lab01/
│   │   └── lab02/
│   │
│   ├── troubleshooting/
│   └── references/
│
├── template_project/
│
├── README.md
└── LICENSE
```

---

# Template Project

The repository includes a fully configured **FreeRTOS SMP Template Project**.

The project already contains:

- FreeRTOS Kernel
- RP2040 port
- FreeRTOS configuration
- Build system
- Project structure

No additional FreeRTOS installation is required.

---

# License

This project is distributed for educational purposes.

Please refer to the LICENSE file for additional information.

---

# Citation

If you use this material in an academic course or research project, please cite this repository.
