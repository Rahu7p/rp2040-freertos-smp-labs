# Chapter 0
# Development Environment

---

This chapter guides you through the installation and verification of the development environment required to complete the laboratories presented in this manual.

By the end of this chapter, your computer should be able to build, program, and execute the provided Template Project.

---

# 1. Required Hardware

The following hardware is required throughout this manual.

| Hardware | Description |
|----------|-------------|
| Pololu Zumo RP2040 Robot | Development platform used in all laboratories |
| USB-C Cable | Programming and serial communication |
| Personal Computer | Windows, Linux, or macOS |

---

# 2. Required Software

Install the following software before continuing.

| Software | Purpose |
|----------|---------|
| Visual Studio Code | Development environment |
| Git | Repository cloning and version control |
| Raspberry Pi Pico Extension | RP2040 development environment |

> [!NOTE]
>
> During its initial configuration, the Raspberry Pi Pico Extension automatically downloads and configures the required development tools, including:
>
> - ARM GNU Toolchain
> - CMake
> - Ninja
> - Pico SDK
> - OpenOCD
> - picotool
>
> No manual installation of these tools is required.

---

# 3. Installing Visual Studio Code

1. Download **Visual Studio Code**.
2. Run the installer.
3. Accept the default installation options.
4. Launch Visual Studio Code.

> **Figure 0.1.** Installing Visual Studio Code.

---

# 4. Installing Git

1. Download **Git**.
2. Install using the default options.
3. Verify the installation by opening a terminal and executing:

```bash
git --version
```

If Git has been installed correctly, its version number should be displayed.

> **Figure 0.2.** Verifying the Git installation.

---

# 5. Installing the Raspberry Pi Pico Extension

Inside Visual Studio Code:

1. Open the **Extensions** panel.
2. Search for:

```text
Raspberry Pi Pico
```

3. Install the official Raspberry Pi Pico Extension.
4. Follow the setup wizard.

During the initial configuration, the extension automatically downloads and configures the required build tools.

> **Figure 0.3.** Installing the Raspberry Pi Pico Extension.

---

# 6. Cloning the Repository

Clone the repository using Git.

```bash
git clone https://github.com/Rahu7p/rp2040-freertos-smp-labs.git
```

Open the cloned repository using Visual Studio Code.

> **Figure 0.4.** Cloning the repository.

---

# 7. Opening the Template Project

Navigate to the following directory.

```text
template_project/
```

Open this folder using Visual Studio Code.

The Template Project contains a fully configured FreeRTOS SMP application that will serve as the starting point for all laboratory activities.

Since the project already includes the FreeRTOS Kernel and all required configuration files, no additional setup is required.

> [!IMPORTANT]
>
> Do not modify the Template Project before completing Laboratory 1.

---

# 8. Building the Project

Build the Template Project using the Raspberry Pi Pico Extension.

The build process should complete successfully without errors.

> **Figure 0.5.** Successful project build.

---

# 9. Programming the RP2040

Connect the Pololu Zumo RP2040 Robot using the USB-C cable.

Program the generated firmware using the Raspberry Pi Pico Extension.

After programming the board, open the Serial Monitor.

The demonstration application should begin executing automatically.

> **Figure 0.6.** Programming the RP2040.

---

# 10. Verifying the Development Environment

Before continuing, verify the following.

- [ ] Visual Studio Code is installed.
- [ ] Git is installed.
- [ ] Raspberry Pi Pico Extension is installed.
- [ ] The repository has been cloned successfully.
- [ ] The Template Project opens correctly.
- [ ] The project builds successfully.
- [ ] The firmware is programmed successfully.
- [ ] The Serial Monitor displays application output.

If all items have been completed successfully, your development environment is ready.

---

# Key Takeaways

After completing this chapter, you should remember the following ideas.

- Visual Studio Code and the Raspberry Pi Pico Extension provide the complete development environment.
- The Raspberry Pi Pico Extension automatically installs the required development tools.
- The Template Project is fully configured and includes the FreeRTOS Kernel.
- The Template Project serves as the starting point for every laboratory.
- No additional project configuration is required before beginning the laboratories.

---

# Preparing for Chapter 1

Your development environment is now ready.

In the next chapter, you will learn why modern embedded systems increasingly rely on multicore processors and how the RP2040 executes multiple FreeRTOS tasks simultaneously using FreeRTOS SMP.
