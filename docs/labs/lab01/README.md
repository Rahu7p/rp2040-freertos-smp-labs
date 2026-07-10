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
