# Chapter 1
# Quick Review: Multicore Fundamentals

---

## Learning Objectives

After completing this chapter, you should be able to:

- Explain why modern embedded systems use multicore processors.
- Differentiate between concurrency and parallelism.
- Identify the main characteristics of the RP2040 multicore architecture.
- Describe how FreeRTOS SMP utilizes both processor cores.
- Apply these concepts during Laboratory 1.

---

## Prerequisites

Before reading this chapter, you should be familiar with:

- C Programming
- Functions and Variables
- Basic Embedded Systems
- Basic FreeRTOS Concepts (Tasks and Scheduler)

---

# 1. Why Multicore?

Embedded systems are becoming increasingly complex. A modern embedded application may need to:

- Read multiple sensors
- Control actuators
- Execute communication protocols
- Process large amounts of data
- Maintain deterministic real-time behavior

Although a single processor can execute many tasks using a Real-Time Operating System (RTOS), all tasks still compete for the same processor core.

Adding additional processor cores allows independent tasks to execute simultaneously, improving responsiveness and increasing the available processing capacity.

---

# 2. Concurrency vs. Parallelism

These two concepts are frequently confused.

**Concurrency** refers to the ability of multiple tasks to make progress during the same period of time. On a single-core processor, this is achieved by rapidly switching the CPU between tasks.

**Parallelism** refers to the simultaneous execution of multiple tasks using multiple processing units.

> [!NOTE]
> Every parallel system is concurrent, but not every concurrent system is parallel.

---

# 3. The RP2040 Multicore Architecture

The RP2040 microcontroller integrates:

- Two ARM Cortex-M0+ processor cores
- Shared SRAM memory
- Dedicated multicore FIFO
- Hardware spinlocks
- Shared peripheral bus

Both cores have access to the same memory space, allowing them to exchange information efficiently.

The RP2040 provides hardware mechanisms to synchronize both processors and safely access shared resources.

---

# 4. FreeRTOS SMP Overview

FreeRTOS SMP extends the traditional FreeRTOS scheduler by allowing tasks to execute on multiple processor cores.

Instead of maintaining an independent scheduler for each core, FreeRTOS SMP manages a common set of ready tasks and dynamically assigns them to the available processors.

Task affinity can optionally be used to restrict a task to execute on a specific processor core.

This flexibility allows developers to balance computational load or dedicate processor cores to time-critical activities.

---

# Key Takeaways

In this chapter you reviewed the fundamental concepts required to understand multicore embedded systems.

The most important ideas are:

- Concurrency and parallelism are different concepts.
- Multicore processors increase processing capability by executing multiple tasks simultaneously.
- The RP2040 contains two ARM Cortex-M0+ cores sharing the same memory.
- FreeRTOS SMP automatically schedules tasks across both cores and optionally supports task affinity.

---

# Preparing for Laboratory 1

In the next laboratory you will observe how the FreeRTOS SMP scheduler distributes tasks across both RP2040 processor cores.

You will also investigate how task affinity influences scheduler behavior and processor utilization.
