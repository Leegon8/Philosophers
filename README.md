# Philosophers

This projects simulates the clasic `Dining Philosophers` problem.
- The philosophers can be in tree states: eating, thinking or sleeping.
- There's the same number of philosophers than forks.
- The philosopher needs two forks to eat.

# Technical requirements
The programs accepts the following argments:
- Number of philosophers.
- Time to die.
- Time to eat.
- Time to sleep.
- (optinal argument) Number of times each philosopher should eat.

# Organization
  <div align="center">
<table>
  <tr>
    <th>1rs Week</th>
    <th>2nd Week</th>
  </tr>
  <tr>
    <td><h4 weigth="bold">Step 1: Initial Configuration</h4><br>- Validate and process input arguments ✅<br>- Create data structures to represent philosophers ✅<br>- Initialize mutex for each fork ✅</td>
    <td><h4 weigth="bold">Step 4: Status Log</h4><br>- Print status changes in the specified format ✅<br>- Include timestamp in milliseconds ✅<br>- Ensure that logs are not mixed ✅</td>
  </tr>
  <tr>
    <td><h4 weigth="bold">Step 2: Thread Implementation</h4><br>- Create a thread for each philosopher ✅<br>- Implement state change logic (eat, think, sleep) ✅<br>- Manage the acquisition and release of forks ✅</td>
     <td><h4 weigth="bold">Step 5: Optimization and Deadlock Prevention</h4><br>- Avoiding deadlocks between philosophers ✅<br>- Implement strategies to prevent starvation ✅<br>- Ensure that all philosophers are able to eat ✅</td>
  </tr>
  <tr>
    <td><h4 weigth="bold">Step 3: Death Management</h4><br>- Implement a mechanism to detect if a philosopher dies of starvation. ✅<br>- Control the maximum time without eating ✅<br>- Stop the simulation if a philosopher dies ✅</td>
    <td><h4 weigth="bold">Step 6: Revision</h4><br>- Verify that there are no leaks or memory segmentation. ✅<br>- Pass the norminette ✅</td>
  </tr>
</table>
