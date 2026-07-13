# Chapter 0
# Development Environment

---

This chapter guides you through the installation and verification of the development environment required for the laboratories.

By the end of this chapter, your computer and RP2040 board should be ready to build, program, and execute the provided Template Project.

---

# 1. Required Hardware

The following hardware is required throughout this manual.

| Hardware | Description |
|----------|-------------|
| Pololu Zumo RP2040 Robot or Raspberry Pico RP2040 Board | Development platform used in all laboratories |
| USB-C Cable | Programming and serial communication |
| Personal Computer | Windows, Linux or macOS |

---

# 2. Required Software

Install the following software before continuing.

| Software | Purpose |
|----------|---------|
| Visual Studio Code | Development Environment |
| Raspberry Pi Pico Extension | RP2040 project management |
| Git | Clone the repository |

> [!NOTE]
>
> The Raspberry Pi Pico Extension automatically installs most required build tools during its initial configuration.

---

# 3. Installing Visual Studio Code

1. Download Visual Studio Code. (https://code.visualstudio.com/)
2. Run the installer.
3. Accept the default installation options.
4. Launch Visual Studio Code.

> **Figure 0.1.** Visual Studio Code installation.

---

# 4. Installing the Raspberry Pi Pico Extension

Open the **Extensions** panel inside Visual Studio Code.

Search for:

```
Raspberry Pi Pico
```

Install the official extension.

> **Figure 0.2.** Raspberry Pi Pico Extension.

---

# 5. Cloning the Repository

Clone the repository using Git.

```bash
git clone https://github.com/Rahu7p/rp2040-freertos-smp-labs.git
```

Open the repository using Visual Studio Code.

> **Figure 0.3.** Repository cloned successfully.

---

# 6. Opening the Template Project

Navigate to:

```text
template_project/
```

Open this folder using Visual Studio Code.

The Template Project contains a fully configured FreeRTOS SMP application that will be used throughout this manual.

Do not modify this project before completing Laboratory 1.

---

# 7. Building the Project

Build the project using the Raspberry Pi Pico Extension.

The build process should complete successfully without errors.

> **Figure 0.4.** Successful build.

---

# 8. Programming the RP2040

Connect the RP2040 board using the USB-C cable.

Program the generated firmware using the Raspberry Pi Pico Extension.

After programming, open the Serial Monitor.

The demonstration application should begin executing automatically.

> **Figure 0.5.** Programming the RP2040.

---

# 9. Verifying the Installation

Before continuing, verify the following.

- [ ] Visual Studio Code is installed.
- [ ] Raspberry Pi Pico Extension is installed.
- [ ] The repository has been cloned successfully.
- [ ] The Template Project opens correctly.
- [ ] The project builds successfully.
- [ ] The firmware can be programmed into the RP2040.
- [ ] The Serial Monitor displays application output.

If every item has been completed successfully, your development environment is ready.

---

# Key Takeaways

After completing this chapter:

- The development environment is fully configured.
- The Template Project builds successfully.
- The RP2040 can be programmed correctly.
- The Serial Monitor is operational.
- You are ready to begin studying multicore embedded systems.

---

# Preparing for Chapter 1

In the next chapter, you will explore why modern embedded systems increasingly rely on multicore processors and how the RP2040 architecture enables parallel execution using FreeRTOS SMP.
