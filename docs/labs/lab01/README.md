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

Identify the processor core executing each FreeRTOS task and observe how the scheduler assigns tasks to the available processor cores.

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

Allow the application to run for approximately **one minute** while observing the Serial Monitor. If no processor core reassignment is observed, continue running the application for a longer period before collecting the required evidence.

---

## Expected Behavior

After running the application:

- Both tasks should continue executing periodically.
- Each message should include the processor core number.
- The scheduler may keep each task on the same processor core for an extended period of time.
- Depending on the scheduler behavior, a task may also be reassigned to the other processor core during execution.

> [!TIP]
> Pay close attention to the processor core number associated with each task. If a task changes from one processor core to the other during execution, identify where the reassignment occurred.

---

## Evidence Collection

Collect the following evidence before continuing.

| Evidence ID | Description |
|--------------|-------------|
| **E2.1** | Capture the modified implementation of `TaskA()` and `TaskB()` showing the use of `get_core_num()`. |
| **E2.2** | Capture the Serial Monitor showing the execution of both tasks. If a processor core reassignment occurs during execution, annotate the image to indicate where the reassignment occurred. Otherwise, indicate that no reassignment was observed during the experiment. |

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

So far, the scheduler has been free to decide where each task executes.

In the next activity, you will configure **task affinity** and compare the scheduler behavior before and after restricting a task to a specific processor core.
