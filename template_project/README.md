# RP2040 FreeRTOS SMP Template Project

This project is the starting point for every laboratory in the **RP2040 FreeRTOS SMP Laboratory Manual**.

It contains a fully configured development environment for the Raspberry Pi RP2040 using the Pico SDK and the FreeRTOS SMP kernel.
---

# Project Contents

This template already includes:

- Raspberry Pi Pico SDK
- FreeRTOS SMP
- CMake build system
- USB Serial communication
- Dual-core support
- Basic project structure

No additional configuration should be required before starting a laboratory.

---

# Project Structure

```text
template_project/

├── cmake/
│   └── FreeRTOS_Kernel_import.cmake
│
├── config/
│   └── FreeRTOSConfig.h
│
├── include/
│
├── src/
│   └── main.c
│
├── CMakeLists.txt
├── pico_sdk_import.cmake
└── README.md
```

---

# Folder Description

| Folder / File | Description |
|----------------|-------------|
| **src/** | Application source code. All laboratory code will be developed here. |
| **include/** | Header files created during the laboratories. |
| **config/** | Project configuration files. |
| **cmake/** | CMake helper files required by the build system. |
| **CMakeLists.txt** | Project build configuration. |
| **pico_sdk_import.cmake** | Imports the Raspberry Pi Pico SDK. |

---

# Before Starting a Laboratory

For every laboratory:

1. Copy this template project.
2. Rename the project folder.
3. Open the project in Visual Studio Code.
4. Build the project.
5. Verify that it compiles successfully.
6. Begin the laboratory.

---

# Files You Will Modify

During the first laboratories, students will only modify:

```text
src/main.c
```

Later laboratories may also require creating files inside:

```text
include/
```

No other project files should be modified unless explicitly indicated in the laboratory instructions.

---

# Building the Project

Open the project using the Raspberry Pi Pico extension in Visual Studio Code.

Then:

1. Configure the project.
2. Build the project.
3. Program the RP2040.
4. Open the Serial Monitor.

If the project compiles successfully and the expected serial output is displayed, the development environment is ready.

---

# Requirements

The template was developed using:

| Tool | Version |
|--------|----------|
| Pico SDK | 2.3.0 |
| FreeRTOS Kernel | V11.x |
| ARM GNU Toolchain | 15.2 |
| Visual Studio Code | Latest |
| Raspberry Pi Pico Extension | Latest |

---

# Troubleshooting

If the project does not compile or execute correctly, refer to:

```
docs/troubleshooting/
```

for the list of known issues and solutions.

---

# Notes

This project is intended exclusively as a starting point for the laboratories included in this repository.

Students are encouraged to experiment with the application source code while preserving the project structure provided by this template.
