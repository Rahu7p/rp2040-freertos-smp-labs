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

# Activity 4. Applying Task Affinity to One Task

---

## Objective

Configure task affinity for a single task and observe how it restricts the scheduler while allowing the remaining tasks to execute without restrictions.

---

## Procedure

Starting from the solution developed in **Activity 3**, configure task affinity only for `TaskA`.
Assign `TaskA` to execute exclusively on **Core 0**.

Use the following function.

```c
vTaskCoreAffinitySet();
```

Do not modify:

- `TaskB`
- `TaskC`
- Task priority
- Task delay
- Scheduler configuration

The only modification in this activity should be the task affinity configuration for `TaskA`.
Build the project and execute the application.
Allow the application to run for approximately **one minute** while observing the Serial Monitor.

---

## Expected Behavior

After running the application:
- `TaskA` should always execute on **Core 0**.
- `TaskB` and `TaskC` should continue executing normally.
- The scheduler remains free to distribute `TaskB` and `TaskC` across the available processor cores.
- The observed task distribution may remain stable or may change during execution, depending on the scheduler behavior.

> [!TIP]
> Compare the execution with Activity 3. Observe how restricting only one task influences the scheduler while the remaining tasks continue executing without affinity.

---

## Evidence Collection

Collect the following evidence before continuing.

| Evidence ID | Description |
|--------------|-------------|
| **E4.1** | Capture the code showing the task affinity configuration for `TaskA`. |
| **E4.2** | Capture the Serial Monitor showing that `TaskA` always executes on **Core 0**. Observe and annotate how the scheduler distributes `TaskB` and `TaskC`. If the task distribution changes during execution, indicate where the change occurred. Otherwise, indicate that the distribution remained unchanged during the experiment. |

---

## Checkpoint

Before continuing to Activity 5, verify the following.

- [ ] The project builds successfully.
- [ ] `TaskA` always executes on **Core 0**.
- [ ] `TaskB` and `TaskC` continue executing periodically.
- [ ] `TaskB` and `TaskC` do not have task affinity configured.
- [ ] All three tasks use the same priority.

---

## Next Activity

So far, only one task has been constrained using task affinity.
In the next activity, you will configure task affinity for multiple tasks and observe how the scheduler manages the remaining unrestricted task.

---

# Activity 5. Applying Task Affinity to Multiple Tasks

---

## Objective

Configure task affinity for multiple tasks and observe how the scheduler manages the remaining unrestricted task.

---

## Procedure

Starting from the solution developed in **Activity 4**, configure task affinity for `TaskB`.

Assign the following processor cores:

- `TaskA` → **Core 0**
- `TaskB` → **Core 1**

Leave `TaskC` without task affinity.

Do not modify:
- Task priority.
- Task delay.
- Scheduler configuration.

The only modification in this activity should be the task affinity configuration for `TaskB`.
Build the project and execute the application.
Allow the application to run for approximately **one minute** while observing the Serial Monitor. If the task distribution appears stable, continue the execution for a longer period before collecting the required evidence.

---

## Expected Behavior

After running the application:
- `TaskA` should always execute on **Core 0**.
- `TaskB` should always execute on **Core 1**.
- `TaskC` remains the only task without affinity.
- The scheduler is free to decide where `TaskC` executes.
- The observed task distribution may remain stable or may change during execution, depending on the scheduler behavior.

> [!TIP]
> Observe the execution of `TaskC`. Since it is the only unrestricted task, it provides insight into how the scheduler makes placement decisions when most tasks already have assigned processor cores.

---

## Evidence Collection

Collect the following evidence before continuing.

| Evidence ID | Description |
|--------------|-------------|
| **E5.1** | Capture the code showing the task affinity configuration for `TaskA` and `TaskB`. |
| **E5.2** | Capture the Serial Monitor showing that `TaskA` always executes on **Core 0** and `TaskB` always executes on **Core 1**. Observe and annotate the execution of `TaskC`. If the scheduler changes the processor core executing `TaskC`, indicate where the change occurred. Otherwise, indicate that the task distribution remained unchanged during the experiment. |

---

## Checkpoint

Before continuing to Activity 6, verify the following.

- [ ] The project builds successfully.
- [ ] `TaskA` always executes on **Core 0**.
- [ ] `TaskB` always executes on **Core 1**.
- [ ] `TaskC` continues executing periodically.
- [ ] `TaskC` does not have task affinity configured.
- [ ] All three tasks use the same priority.

---

## Next Activity

So far, all tasks have executed with the same priority.
In the next activity, you will investigate how **task priority** influences scheduler decisions in a multicore FreeRTOS SMP system.

---

# Activity 6. Understanding the Effect of Task Priority

---

## Objective

Investigate how task priority influences scheduler behavior when a high-priority task does and does not voluntarily release the processor.

---

## Procedure

Starting from the solution developed in **Activity 5**, keep the following configuration:

| Task | Priority | Affinity |
|-------|----------|----------|
| TaskA | Normal | Core 0 |
| TaskB | Normal | Core 1 |
| TaskC | Higher | None |

Perform the following experiments.

---

### Experiment 1 - Continuous Execution

Modify `TaskC` by removing its delay.

```c
while (1)
{
    printf("Task C -> Core %u\r\n", get_core_num());
}
```

Build and execute the application.
Observe the Serial Monitor for approximately **30 seconds**.

---

### Experiment 2 - Periodic Blocking

Restore `TaskC` and insert a delay of **1 ms**.

```c
while (1)
{
    printf("Task C -> Core %u\r\n", get_core_num());

    vTaskDelay(pdMS_TO_TICKS(1));
}
```

Build and execute the application again.
Observe the Serial Monitor for approximately **30 seconds**.

---

## Expected Behavior

### Experiment 1

- `TaskC` executes continuously.
- `TaskC` does not voluntarily release the processor.
- Observe how this affects the execution of `TaskA` and `TaskB`.

### Experiment 2

- `TaskC` periodically releases the processor.
- Observe whether `TaskA` and `TaskB` execute more frequently than in Experiment 1.

> [!TIP]
> Compare both experiments carefully. The only modification is the presence of `vTaskDelay()` inside the highest-priority task.

---

## Evidence Collection

Collect the following evidence before completing the laboratory.

| Evidence ID | Description |
|--------------|-------------|
| **E6.1** | Capture the modified implementation of `TaskC()` for both experiments. |
| **E6.2** | Capture the Serial Monitor for **Experiment 1**. Describe the observed behavior of the three tasks. |
| **E6.3** | Capture the Serial Monitor for **Experiment 2**. Describe how the execution changed after adding `vTaskDelay(1 ms)` to `TaskC`. |

---

## Checkpoint

Before completing the laboratory, verify the following.

- [ ] The project builds successfully.
- [ ] `TaskC` executes with a higher priority than the other tasks.
- [ ] Both experiments were completed.
- [ ] The execution behavior of the scheduler was compared between both experiments.

---

## Laboratory Summary

During this laboratory, you investigated how the FreeRTOS SMP scheduler behaves in a multicore embedded system.

You explored:
- Creating multiple FreeRTOS tasks.
- Identifying the processor core executing each task.
- Observing task distribution across two processor cores.
- Restricting scheduler decisions using task affinity.
- Applying task affinity to multiple tasks.
- Investigating the effect of task priority on scheduler behavior.

One of the most important observations is that **task priority alone does not guarantee a visible change in execution**. The scheduler makes decisions based on both **task priority** and **task state**.
A high-priority task that never blocks can monopolize processor time, while a high-priority task that periodically blocks allows lower-priority tasks to execute.
Understanding this interaction between **priority**, **task state**, and **scheduler decisions** is fundamental when designing responsive and efficient real-time embedded systems.
