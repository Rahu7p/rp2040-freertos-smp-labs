# Laboratory 1
# Discovering the FreeRTOS SMP Scheduler

---

## Guiding Question

**How does the FreeRTOS SMP scheduler decide where a task executes?**

---

## Required Material

### Hardware

- Pololu Zumo RP2040 Robot
- USB-C Cable

### Software

- Visual Studio Code | Raspberry Pi Pico Extension
- RP2040 FreeRTOS SMP Template Project

---

# Activity 1. Observing the Scheduler

---

## Objective

Create two identical FreeRTOS tasks and observe their execution through the serial terminal before introducing multicore-specific features.

---

## Estimated Time

15–20 minutes

---

## Procedure

1. Open the **Template Project**. (https://github.com/Rahu7p/rp2040-freertos-smp-labs/tree/main/template_project)
2. Create two FreeRTOS tasks named:
   - `TaskA`
   - `TaskB`
3. Configure both tasks with:
   - The same priority.
   - An infinite execution loop.
   - A delay of **500 ms** between iterations.
4. Do **not** configure task affinity.
5. Start the scheduler.

Use the following `main()` structure as a reference.

```c
int main(void)
{
    stdio_init_all();
    sleep_ms(2000);

    // Create TaskA

    // Create TaskB

    vTaskStartScheduler();
    while (1) {
    }
}
```

The serial terminal should display output similar to the following:

Example:

```text
Task A
Task B
Task A
Task B
Task A
Task B
...
```

---

## Expected Behavior

After running the application:
- Both tasks should execute periodically.
- Since no multicore information is printed, it should not be possible to determine which processor core executed each task.

---

## Evidence Collection

Collect the following evidence before continuing.

| Evidence ID | Description |
|--------------|-------------|
| **E1.1** | Screenshot of the implementation of `TaskA()` and `TaskB()`. |
| **E1.2** | Screenshot of the `main()` function showing the creation of both tasks and the scheduler startup. |
| **E1.3** | Screenshot of the Serial Monitor showing both tasks executing periodically. |
| **E1.4** | Screenshot showing that the project builds successfully without errors. |

---

## Checkpoint

Before continuing to Activity 2, verify the following.

- [ ] The project builds successfully.
- [ ] The application executes correctly.
- [ ] TaskA executes periodically.
- [ ] TaskB executes periodically.
- [ ] Both tasks use the same priority.
- [ ] No task affinity has been configured.
- [ ] The Serial Monitor shows continuous execution of both tasks.

---

## Next Activity

At this point, you can observe **which task** is executing, but you cannot determine **which processor core** executed the task.
In the next activity, you will identify the processor core executing each task and compare the observed behavior with the expected scheduler operation.

---

# Activity 2. Identifying the Executing Core

---

## Objective

Identify the processor core executing each FreeRTOS task and investigate how the scheduler assigns tasks to the available processor cores.

---

## Procedure

Starting from the solution developed in **Activity 1**, modify both tasks to display the processor core executing each task.

Use the following function.

```c
get_core_num();
```

Each task should now print both its name and the processor core number.

Example:

```text
Task A -> Core 0
Task B -> Core 1
Task A -> Core 0
Task B -> Core 1
...
```

Build the project and execute the application.
Allow the application to run for approximately **one minute** while observing the Serial Monitor. If the scheduler behavior appears stable, continue the execution for a longer period before collecting the required evidence.

---

## Expected Behavior

After running the application:
- Both tasks should continue executing periodically.
- Each message should include the processor core number.
- The scheduler will assign each task to one of the available processor cores.
- The observed task distribution may remain stable or may change during execution, depending on the scheduler behavior.

> [!TIP]
> Observe the processor core associated with each task during the entire execution. Pay special attention to any changes in the task distribution between the two processor cores.

---

## Evidence Collection

Collect the following evidence before continuing.

| Evidence ID | Description |
|--------------|-------------|
| **E2.1** | Capture the modified implementation of `TaskA()` and `TaskB()` showing the use of `get_core_num()`. |
| **E2.2** | Capture the Serial Monitor showing the execution of both tasks. If the task distribution changes during execution, annotate the image to indicate where the change occurred. Otherwise, indicate that the task distribution remained unchanged during the experiment. |

---

## Checkpoint

Before continuing to Activity 3, verify the following.

- [ ] The project builds successfully.
- [ ] Both tasks continue executing periodically.
- [ ] The processor core number is displayed correctly.
- [ ] The Serial Monitor clearly identifies the processor core executing each task.
- [ ] No task affinity has been configured.

---

## Next Activity

So far, the scheduler has been free to assign two tasks across two processor cores.
In the next activity, you will increase the number of ready tasks and investigate how the scheduler distributes the workload when the number of tasks exceeds the number of available processor cores.

---

# Activity 3. Task Distribution Across Two Processor Cores

---

## Objective

Observe how the FreeRTOS SMP scheduler distributes multiple ready tasks when the number of tasks exceeds the number of available processor cores.

---

## Procedure

Starting from the solution developed in **Activity 2**, create a third FreeRTOS task named `TaskC`.

Configure the new task with:
- The same priority as `TaskA` and `TaskB`.
- The same execution period (**500 ms**).
- No task affinity.

Do not modify:
- Task priority.
- Task delay.
- Scheduler configuration.

The only modification in this activity should be the addition of `TaskC`.
Each task should continue displaying both its name and the processor core number.

Example:

```text
Task A -> Core 1
Task B -> Core 0
Task C -> Core 0
...
```

Build the project and execute the application.
Allow the application to run for approximately **one minute** while observing the Serial Monitor. If the task distribution appears stable, continue the execution for a longer period before collecting the required evidence.

---

## Expected Behavior

After running the application:
- All three tasks should execute periodically.
- Each task should display the processor core executing it.
- Since only two processor cores are available, the scheduler must distribute three ready tasks across the available processor cores.
- The observed task distribution may remain stable or may change during execution, depending on the scheduler behavior.

> [!TIP]
> Observe how the scheduler distributes the three tasks across the two processor cores. Pay special attention to any changes in the task distribution during execution.

---

## Evidence Collection

Collect the following evidence before continuing.

| Evidence ID | Description |
|--------------|-------------|
| **E3.1** | Capture the code showing the creation of `TaskC`. |
| **E3.2** | Capture the Serial Monitor showing the execution of the three tasks. If the task distribution changes during execution, annotate the image to indicate where the change occurred. Otherwise, indicate that the task distribution remained unchanged during the experiment. |

---

## Checkpoint

Before continuing to Activity 4, verify the following.

- [ ] The project builds successfully.
- [ ] All three tasks execute periodically.
- [ ] The processor core number is displayed correctly.
- [ ] No task affinity has been configured.
- [ ] All three tasks use the same priority.

---

## Optional Exploration

Create a fourth FreeRTOS task named `TaskD`.

Configure `TaskD` with:
- The same priority as the other tasks.
- The same execution period (**500 ms**).
- No task affinity.

Do not modify any other part of the application.
Build and execute the project.
Observe how the scheduler distributes **four tasks** across the **two processor cores**.

While observing the Serial Monitor, pay attention to the following:
- How are the four tasks distributed across the two processor cores?
- Does the task distribution remain stable?
- Does the scheduler reorganize the task distribution during execution?

> [!TIP]
> This exploration is optional and is intended to further investigate the behavior of the FreeRTOS SMP scheduler. No additional evidence is required.

---

## Next Activity

So far, the scheduler has been free to decide where every task executes.
In the next activity, you will configure **task affinity** and observe how restricting a single task influences the scheduler's decisions.

---

