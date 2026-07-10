# RP2040 FreeRTOS SMP Template Project

This project serves as the starting point for every laboratory in the **RP2040 FreeRTOS SMP Laboratory Manual**.

It provides a fully configured development environment for the Raspberry Pi RP2040 using the Pico SDK and the FreeRTOS SMP kernel.

---

# Project Contents

This template already includes:

- Raspberry Pi Pico SDK
- FreeRTOS SMP
- CMake build system
- USB Serial communication
- Dual-core support
- Standard project structure

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
|---------------|-------------|
| **src/** | Application source code. Most laboratory activities will be implemented here. |
| **include/** | Header files created during the laboratories. |
| **config/** | Project configuration files. |
| **cmake/** | Helper CMake files required by the build system. |
| **CMakeLists.txt** | Main project configuration file. |
| **pico_sdk_import.cmake** | Imports the Raspberry Pi Pico SDK. |

---

# Project File Categories

Not all files in the project have the same purpose. During this course, it is important to distinguish between application code, configuration files, and framework files.

| Category | Files | Description |
|----------|-------|-------------|
| **Application Files** | `src/`, `include/` | Source code written by the student. Most laboratory work will take place here. |
| **Configuration Files** | `config/`, `CMakeLists.txt` | Project settings that define how the application is built. These files should only be modified when instructed. |
| **Framework Files** | `pico_sdk_import.cmake`, `cmake/FreeRTOS_Kernel_import.cmake` | Files provided by the Pico SDK and FreeRTOS integration. They normally remain unchanged. |

> [!IMPORTANT]
>
> During the laboratories, modify only the files explicitly indicated in the laboratory instructions.
>
> Avoid changing framework or configuration files unless the activity specifically requires it.

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

As the course progresses, additional header files may be created inside:

```text
include/
```

No other project files should be modified unless explicitly requested by the laboratory instructions.

---

# Building the Project

Open the project using the Raspberry Pi Pico Extension in Visual Studio Code.

Then:

1. Configure the project.
2. Build the project.
3. Program the RP2040.
4. Open the Serial Monitor.
5. Verify the expected output.

If the application builds successfully and the expected serial output is displayed, the development environment is ready.

---

# Software Versions

The template has been tested with the following tools.

| Tool | Version |
|------|---------|
| Pico SDK | 2.3.0 |
| FreeRTOS Kernel | V11.x |
| ARM GNU Toolchain | 15.2 Rel1 |
| Visual Studio Code | Latest |
| Raspberry Pi Pico Extension | Latest |

---

# Troubleshooting

If the project does not compile or execute correctly, refer to:

```text
docs/troubleshooting/
```

for a list of common issues and recommended solutions.

---

# Notes

This project is intended exclusively as the starting point for the laboratories included in this repository.

Students are encouraged to experiment with the application source code while preserving the overall project structure provided by this template.

---

# Repository

For the complete laboratory manual, documentation, and additional resources, return to the repository home page.

```
RP2040 FreeRTOS SMP Laboratory Manual
```
